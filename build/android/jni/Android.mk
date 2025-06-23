LOCAL_PATH := $(call my-dir)/../../../src
$(info $(LOCAL_PATH))
include $(CLEAR_VARS)  
LOCAL_LDLIBS := -lEGL -lGLESv1_CM -ldl
LOCAL_MODULE    := glshim
GL_SRC_FILES := $(wildcard $(LOCAL_PATH)/gl/*.c) $(wildcard $(LOCAL_PATH)/gl/wrap/*.c) $(wildcard $(LOCAL_PATH)/gl/math/*.c)
LOCAL_SRC_FILES := $(GL_SRC_FILES:$(LOCAL_PATH)/%=%)
$(info $(LOCAL_SRC_FILES))
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include $(LOCAL_PATH)/util
APP_CPPFLAGS += -std=c++11
LOCAL_CFLAGS += -Wno-typedef-redefinition -Wno-dangling-else -Wno-error-implicit-function-declaration -std=gnu99
LOCAL_CFLAGS += -DANDROID -pipe -integrated-as -fno-plt -O3 -flto=auto -mllvm -polly -mllvm -polly-vectorizer=stripmine -mllvm -polly-invariant-load-hoisting -mllvm -polly-run-inliner -mllvm -polly-run-dce -funwind-tables -O3 -fvisibility=hidden -fno-semantic-interposition
LOCAL_CFLAGS += -DNOX11
LOCAL_CFLAGS += -DNO_GBM -DBOARDWALK_POTATO
include $(BUILD_SHARED_LIBRARY)
