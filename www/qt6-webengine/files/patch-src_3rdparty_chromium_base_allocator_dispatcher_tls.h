--- src/3rdparty/chromium/base/allocator/dispatcher/tls.h.orig	2024-05-21 18:07:39 UTC
+++ src/3rdparty/chromium/base/allocator/dispatcher/tls.h
@@ -77,7 +77,7 @@ struct BASE_EXPORT MMapAllocator {
   constexpr static size_t AllocationChunkSize = 16384;
 #elif BUILDFLAG(IS_ANDROID) && defined(ARCH_CPU_64_BITS)
   constexpr static size_t AllocationChunkSize = 16384;
-#elif BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
   constexpr static size_t AllocationChunkSize = 16384;
 #else
   constexpr static size_t AllocationChunkSize = 4096;
