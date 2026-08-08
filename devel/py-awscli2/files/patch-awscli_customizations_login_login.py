--- awscli/customizations/login/login.py.orig	2026-07-31 18:06:47 UTC
+++ awscli/customizations/login/login.py
@@ -52,7 +52,7 @@ class LoginCommand(BasicCommand):
         {
             'name': 'remote',
             'action': 'store_true',
-            'default': False,
+            'default': True,
             'help_text': (
                 'Disables the local callback server and redirect-based auth '
                 'flow. Instead displays the URL and prompts you to paste the '
