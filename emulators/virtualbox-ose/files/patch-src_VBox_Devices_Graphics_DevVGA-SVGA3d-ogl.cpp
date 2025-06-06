--- src/VBox/Devices/Graphics/DevVGA-SVGA3d-ogl.cpp.orig	2024-01-11 12:18:21 UTC
+++ src/VBox/Devices/Graphics/DevVGA-SVGA3d-ogl.cpp
@@ -1189,7 +1189,7 @@ int vmsvga3dTerminate(PVGASTATECC pThisCC)
     RTSemEventDestroy(pState->WndRequestSem);
 #elif defined(RT_OS_DARWIN)
 
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     /* signal to the thread that it is supposed to exit */
     pState->bTerminate = true;
     /* wait for it to terminate */
@@ -3194,7 +3194,7 @@ int vmsvga3dGenerateMipmaps(PVGASTATECC pThisCC, uint3
 }
 
 
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 /**
  * X11 event handling thread.
  *
@@ -3224,7 +3224,7 @@ DECLCALLBACK(int) vmsvga3dXEventThread(RTTHREAD hThrea
     }
     return VINF_SUCCESS;
 }
-#endif // RT_OS_LINUX
+#endif // RT_OS_FREEBSD || RT_OS_LINUX
 
 
 /**
@@ -3461,7 +3461,7 @@ int vmsvga3dContextDefineOgl(PVGASTATECC pThisCC, uint
     return VINF_SUCCESS;
 }
 
-#if defined(RT_OS_LINUX)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
 /*
  * HW accelerated graphics output.
  */
@@ -3932,7 +3932,7 @@ int vmsvga3dBackSurfaceBlitToScreen(PVGASTATECC pThisC
     return VINF_SUCCESS;
 }
 
-#else /* !RT_OS_LINUX */
+#else /* !RT_OS_FREEBSD && !RT_OS_LINUX */
 
 int vmsvga3dBackDefineScreen(PVGASTATE pThis, PVGASTATECC pThisCC, VMSVGASCREENOBJECT *pScreen)
 {
@@ -4052,7 +4052,7 @@ static int vmsvga3dContextDestroyOgl(PVGASTATECC pThis
     AssertRC(rc);
 #elif defined(RT_OS_DARWIN)
     vmsvga3dCocoaDestroyViewAndContext(pContext->cocoaView, pContext->cocoaContext);
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
     glXMakeCurrent(pState->display, None, NULL);
     glXDestroyContext(pState->display, pContext->glxContext);
     XDestroyWindow(pState->display, pContext->window);
