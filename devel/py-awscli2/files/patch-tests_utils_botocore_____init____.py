--- tests/utils/botocore/__init__.py.orig	2026-08-03 18:27:57 UTC
+++ tests/utils/botocore/__init__.py
@@ -65,7 +65,7 @@ def skip_unless_has_memory_collection(cls):
     indicate that if the platform does not support memory collection
     the tests should be skipped.
     """
-    if platform.system() not in ['Darwin', 'Linux']:
+    if platform.system() not in ['Darwin', 'Linux', 'FreeBSD']:
         return unittest.skip('Memory tests only supported on mac/linux.')(cls)
     return cls
 
@@ -80,7 +80,7 @@ def skip_if_windows(reason):
 
     def decorator(func):
         return unittest.skipIf(
-            platform.system() not in ['Darwin', 'Linux'], reason
+            platform.system() not in ['Darwin', 'Linux', 'FreeBSD'], reason
         )(func)
 
     return decorator
