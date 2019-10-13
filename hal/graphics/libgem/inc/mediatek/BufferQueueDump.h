#pragma GCC system_header
/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_GUI_BUFFERQUEUEDUMP_H
#define ANDROID_GUI_BUFFERQUEUEDUMP_H

#include <ui/Fence.h>
#include <ui/GraphicBuffer.h>
#include <mediatek/IDumpTunnel.h>

#include <utils/KeyedVector.h>

#include <mediatek/RingBuffer.h>

namespace android {
// ----------------------------------------------------------------------------
class BufferQueue;
class DumpBuffer;
class BackupBuffer;
class BackupBufPusher;
class BackupBufDumper;
class BufferQueueCore;

// class for BufferQueue backup and dump utils impl
class BufferQueueDump : public BnDumpTunnel {
public:
    enum MODE {
        TRACK_PRODUCER = 0,
        TRACK_CONSUMER
    };

private:
    String8 mName;
    String8 mKeyName;

    // RingBuffer utils for buffer backup storage
    RingBuffer< sp<BackupBuffer> > mBackupBuf;
    sp<BackupBufPusher> mBackupBufPusher;
    sp<BackupBufDumper> mBackupBufDumper;
    bool mIsBackupBufInited;
    MODE mMode;

    // for IDumpTunnel interface
    wp<BufferQueueCore> mBq;
    bool mIsRegistered;

    // keep reference for
    DefaultKeyedVector< uint32_t, sp<DumpBuffer> > mObtainedBufs;
    sp<DumpBuffer> mLastObtainedBuf;

    // update buffer into back up
    void updateBuffer(const int& slot, const int64_t& timestamp = -1);

    // add buffer into back update
    void addBuffer(const int& slot,
                   const sp<GraphicBuffer>& buffer,
                   const sp<Fence>& fence,
                   const int64_t& timestamp = -1,
                   const uint32_t& transform = 0xFF);

    // check backup depth setting, and reset length if changed
    int checkBackupCount();

    // check backup depth setting, and reset length if changed
    unsigned int checkBackupCnt(char* str);

    // parse/match functions
    bool matchCName(char* str);
    bool matchProc(char* str);
    int match(char* substr);
    bool parseDumpConfig(const char* value, uint32_t* pBackupCnt);

    // set backup count after parsing
    void setBackupCount(uint32_t count);

    // dump mObtainedBufs when dump buffers
    void dumpObtainedBufs();

    // consumer's pid and process name
    int32_t mPid;
    String8 mProcName;

public:
    BufferQueueDump(const MODE& mode, const wp<BufferQueueCore>& bq);

    // name for this dump
    void setName(const String8& name);

    // trigger the dump process
    void dump(String8& result, const char* prefix);

    // related functions into original BufferQueue APIs
    void onAcquireBuffer(const int& slot,
                         const sp<GraphicBuffer>& buffer,
                         const sp<Fence>& fence,
                         const int64_t& timestamp,
                         const uint32_t& transform);
    void onReleaseBuffer(const int& slot);
    void onFreeBuffer(const int& slot);
    void onDequeueBuffer(const int& slot,
                         const sp<GraphicBuffer>& buffer,
                         const sp<Fence>& fence);
    void onQueueBuffer(const int& slot, const int64_t& timestamp);
    void onCancelBuffer(const int& slot);
    void onConsumerDisconnect();

    // generate path for file dump
    static void getDumpFileName(String8& fileName, const String8& name);

    // IDump interface
    virtual status_t kickDump(String8& /*result*/, const char* /*prefix*/);

    // check register status
    bool isRegistered() { return mIsRegistered; }
    void setRegistered(const bool& isRegistered) {
        if (mIsRegistered && !isRegistered)
            mBq = NULL;
        mIsRegistered = isRegistered;
    }
    void setKeyName(const String8& name) { mKeyName = name; }
    const String8& getKeyName() { return mKeyName; }
};


// implement of buffer push
class BackupBufPusher : public RingBuffer< sp<BackupBuffer> >::Pusher {
public:
    BackupBufPusher(RingBuffer< sp<BackupBuffer> >& rb) :
        RingBuffer< sp<BackupBuffer> >::Pusher(rb) {}

    // the main API to implement
    virtual bool push(const sp<BackupBuffer>& in);
};


// implement of buffer dump
class BackupBufDumper : public RingBuffer< sp<BackupBuffer> >::Dumper {
private:
    String8 mName;

public:
    BackupBufDumper(RingBuffer< sp<BackupBuffer> >& rb)
        : RingBuffer< sp<BackupBuffer> >::Dumper(rb)
        , mName("unnamed BackupBufDumper") {}

    void setName(const String8& name) { mName = name; }

    // the main API to implement
    virtual void dump(String8& result, const char* prefix);
};


// struct of record for acquired buffer
class DumpBuffer : public LightRefBase<DumpBuffer> {
public:
    DumpBuffer(const sp<GraphicBuffer> buffer = NULL,
                   const sp<Fence>& fence = Fence::NO_FENCE,
                   int64_t timestamp = 0,
                   uint32_t transform = 0xFF)
        : mGraphicBuffer(buffer)
        , mFence(fence)
        , mTimeStamp(timestamp)
        , mTransform(transform) {}

    sp<GraphicBuffer> mGraphicBuffer;
    sp<Fence> mFence;
    int64_t mTimeStamp;
    uint32_t mTransform;

    void dump(const String8& prefix);
};


// struct of record for backup buffer
class BackupBuffer : public LightRefBase<BackupBuffer> {
public:
    BackupBuffer(const sp<GraphicBuffer> buffer = NULL,
                 nsecs_t timestamp = 0)
        : mGraphicBuffer(buffer)
        , mTimeStamp(timestamp)
        , mSourceHandle(NULL) {}

    sp<GraphicBuffer> mGraphicBuffer;
    nsecs_t mTimeStamp;
    const void* mSourceHandle;
};

// ----------------------------------------------------------------------------
}; // namespace android

#endif // ANDROID_GUI_BUFFERQUEUEDUMP_H
