--- deps/hiredis/net.c.orig	2024-04-01 02:56:24 UTC
+++ deps/hiredis/net.c
@@ -185,14 +185,34 @@ int redisKeepAlive(redisContext *c, int interval) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
         return REDIS_ERR;
     }
-#else
-#if defined(__GLIBC__) && !defined(__FreeBSD_kernel__)
+#elif defined(__GLIBC__)
     if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
         return REDIS_ERR;
     }
 
     val = interval/3;
+    if (val == 0) val = 1;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+
+    val = 3;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+#else
+#if !defined(__sun) && defined(TCP_KEEPIDLE) && defined(TCP_KEEPINTL) && \
+    defined(TCP_KEEPCNT)
+    val = interval;
+    if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &val, sizeof(val)) < 0) {
+        __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
+        return REDIS_ERR;
+    }
+
+    val = internal/3;
     if (val == 0) val = 1;
     if (setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &val, sizeof(val)) < 0) {
         __redisSetError(c,REDIS_ERR_OTHER,strerror(errno));
