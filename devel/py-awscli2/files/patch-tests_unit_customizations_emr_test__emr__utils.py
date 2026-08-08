--- tests/unit/customizations/emr/test_emr_utils.py.orig	2026-08-03 18:27:57 UTC
+++ tests/unit/customizations/emr/test_emr_utils.py
@@ -16,7 +16,7 @@ class TestEMRutils:
 
 class TestEMRutils:
     def test_which_with_existing_command(self):
-        pythonPath = which('python') or which('python.exe')
+        pythonPath = which('%%PYTHON_CMD%%') or which('python.exe')
         assert pythonPath is not None
 
     def test_which_with_non_existing_command(self):
