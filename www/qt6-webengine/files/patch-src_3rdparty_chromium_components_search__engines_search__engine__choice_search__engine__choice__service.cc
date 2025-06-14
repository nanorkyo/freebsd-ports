--- src/3rdparty/chromium/components/search_engines/search_engine_choice/search_engine_choice_service.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/search_engines/search_engine_choice/search_engine_choice_service.cc
@@ -594,7 +594,7 @@ void SearchEngineChoiceService::RegisterLocalStatePref
 
 int SearchEngineChoiceService::GetCountryIdInternal() {
   // `country_codes::kCountryIDAtInstall` may not be set yet.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Android, ChromeOS and Linux, `country_codes::kCountryIDAtInstall` is
   // computed asynchronously using platform-specific signals, and may not be
   // available yet.
