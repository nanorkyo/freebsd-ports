--- awscli/testutils.py.orig	2026-08-03 18:27:57 UTC
+++ awscli/testutils.py
@@ -72,7 +72,7 @@ def skip_if_windows(reason):
 
     def decorator(func):
         return unittest.skipIf(
-            platform.system() not in ['Darwin', 'Linux'], reason
+            platform.system() not in ['Darwin', 'Linux', 'FreeBSD'], reason
         )(func)
 
     return decorator
@@ -790,6 +790,8 @@ def _wait_and_collect_mem(process):
     if platform.system() == 'Darwin':
         get_memory = _get_memory_with_ps
     elif platform.system() == 'Linux':
+        get_memory = _get_memory_with_ps
+    elif platform.system() == 'FreeBSD':
         get_memory = _get_memory_with_ps
     else:
         raise ValueError(
