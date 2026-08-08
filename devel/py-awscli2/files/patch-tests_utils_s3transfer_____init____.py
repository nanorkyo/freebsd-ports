--- tests/utils/s3transfer/__init__.py.orig	2026-08-03 18:27:57 UTC
+++ tests/utils/s3transfer/__init__.py
@@ -107,7 +107,7 @@ def skip_if_windows(reason):
 
     def decorator(func):
         return unittest.skipIf(
-            platform.system() not in ['Darwin', 'Linux'], reason
+            platform.system() not in ['Darwin', 'Linux', 'FreeBSD'], reason
         )(func)
 
     return decorator
