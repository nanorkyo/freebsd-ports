--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc
@@ -54,7 +54,7 @@
 #include "third_party/blink/public/mojom/webdatabase/web_database.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #include "content/browser/media/video_encode_accelerator_provider_launcher.h"
@@ -348,7 +348,7 @@ void RenderProcessHostImpl::IOThreadHostImpl::BindHost
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
