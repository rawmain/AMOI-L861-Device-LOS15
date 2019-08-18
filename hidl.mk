# Power
PRODUCT_PACKAGES += \
	android.hardware.power@1.0-impl \
	android.hardware.thermal@1.1-impl
	
# Wifi
PRODUCT_PACKAGES += \
	android.hardware.wifi@1.0-service

#GNSS HAL
PRODUCT_PACKAGES += \
    android.hardware.gnss@1.0-impl

# GPS force mode
PRODUCT_PROPERTY_OVERRIDES += \
    persist.force.gps.mode=gnss

#Audio HIDL
PRODUCT_PACKAGES += \
    android.hardware.audio@2.0-impl \
    android.hardware.audio@2.0-service \
    android.hardware.audio.effect@2.0-impl \
    android.hardware.broadcastradio@1.0-impl \
    android.hardware.soundtrigger@2.0-impl


# NFC HIDL
#	vendor.nxp.hardware.nfc@1.0-service \
#	vendor.nxp.hardware.nfc@1.0_hal \
# 	android.hardware.nfc@1.0-impl \

#PRODUCT_PACKAGES += \
#	android.hardware.nfc@1.0-impl \
#	android.hardware.nfc@1.0-service
	

	
#gralloc/graphics HAL/HW Composer
PRODUCT_PACKAGES += \
    android.hardware.graphics.allocator@2.0-impl \
    android.hardware.graphics.allocator@2.0-service \
    android.hardware.graphics.composer@2.1-impl \
    android.hardware.graphics.mapper@2.0-impl \
    android.hardware.renderscript@1.0-impl

#memtrack
PRODUCT_PACKAGES += \
    android.hardware.memtrack@1.0-impl \
    android.hardware.memtrack@1.0-service

# Camera HAL
#    camera.device@3.2-impl \
#     android.hardware.camera.provider@2.4-service
#    android.hardware.camera.provider@2.4-impl \
# camera.device@1.0-impl \

#   camera.device@1.0-impl \
#	camera.device@1.0-impl-legacy \
#     camera.device@1.0-impl \
#Camera HAL
#
#
#	camera.device@1.0-impl \
#    camera.device@3.2-impl \
#    camera.device@3.3-impl \
#    android.hardware.camera.provider@2.4-impl \
#
#Camera HAL
PRODUCT_PACKAGES += \
		android.hardware.camera.provider@2.4-impl \

#	camera.device@1.0-impl \
#	camera.device@3.2-impl \
#    camera.device@3.3-impl \
#	android.hardware.camera.provider@2.4-impl \
    
#	android.hardware.camera.provider@2.4-service \
#	camera.device@1.0-impl \
#	camera.device@3.2-impl \
#    camera.device@3.3-impl \
    
	
#	android.hardware.camera.provider@2.4-impl \
#	android.hardware.camera.provider@2.4-impl-legacy \
#	android.hardware.camera.provider@2.4-service \
    
#    android.hardware.camera.provider@2.4-impl \
#    android.hardware.camera.provider@2.4-service
    

   

# Bluetooth HAL
PRODUCT_PACKAGES += \
    android.hardware.bluetooth@1.0-impl \
#    android.hardware.bluetooth@1.0-service

#USB HAL
PRODUCT_PACKAGES += \
    android.hardware.usb@1.0-service

# Omx
PRODUCT_PACKAGES += \
    android.hardware.media.omx@1.0

# Keymaster HIDL
PRODUCT_PACKAGES += \
    android.hardware.keymaster@3.0-impl \
    android.hardware.keymaster@3.0-service

# Gatekeeper HIDL
PRODUCT_PACKAGES += \
    android.hardware.gatekeeper@1.0-impl \
#   android.hardware.gatekeeper@1.0-service

# Vibrator
PRODUCT_PACKAGES += \
    android.hardware.vibrator@1.0-impl \
    android.hardware.vibrator@1.0-service

# Lights
PRODUCT_PACKAGES += \
    android.hardware.light@2.0-impl \
    android.hardware.light@2.0-service

# Sensors
PRODUCT_PACKAGES += \
    android.hardware.sensors@1.0-impl \
    android.hardware.sensors@1.0-service

# Drm
PRODUCT_PACKAGES += \
    android.hardware.drm@1.0-impl

# Health
PRODUCT_PACKAGES += \
    android.hardware.health@1.0-impl \
    android.hardware.health@1.0-service

# Fingerprint
# PRODUCT_PACKAGES += \
#    android.hardware.biometrics.fingerprint@2.0-service

# Ril
PRODUCT_PACKAGES += \
    android.hardware.radio@1.0 \
    android.hardware.radio@1.1 \
    android.hardware.radio.deprecated@1.0

# Tether Packages
PRODUCT_PACKAGES += \
    android.hardware.tetheroffload.config@1.0 \
    android.hardware.tetheroffload.control@1.0
