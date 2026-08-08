--- tests/markers.py.orig	2026-02-27 19:05:56 UTC
+++ tests/markers.py
@@ -3,10 +3,10 @@ skip_if_windows = pytest.mark.skipif(
 import pytest
 
 skip_if_windows = pytest.mark.skipif(
-    platform.system() not in ['Darwin', 'Linux'],
+    platform.system() not in ['Darwin', 'Linux', 'FreeBSD'],
     reason="This test does not run on windows.",
 )
 if_windows = pytest.mark.skipif(
-    platform.system() in ['Darwin', 'Linux'],
+    platform.system() in ['Darwin', 'Linux', 'FreeBSD'],
     reason="This test only runs on windows.",
 )
