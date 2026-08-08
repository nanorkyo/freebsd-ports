--- awscli/customizations/sso/utils.py.orig	2025-11-24 19:05:22 UTC
+++ awscli/customizations/sso/utils.py
@@ -46,7 +46,7 @@ LOGIN_ARGS = [
     {
         'name': 'no-browser',
         'action': 'store_true',
-        'default': False,
+        'default': True,
         'help_text': (
             'Disables automatically opening the verification URL in the '
             'default browser.'
@@ -55,7 +55,7 @@ LOGIN_ARGS = [
     {
         'name': 'use-device-code',
         'action': 'store_true',
-        'default': False,
+        'default': True,
         'help_text': (
             'Uses the Device Code authorization grant and login flow '
             'instead of the Authorization Code flow.'
