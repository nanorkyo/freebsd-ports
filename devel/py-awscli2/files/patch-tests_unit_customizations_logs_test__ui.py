--- tests/unit/customizations/logs/test_ui.py.orig	2026-05-07 18:28:14 UTC
+++ tests/unit/customizations/logs/test_ui.py
@@ -374,6 +374,8 @@ class LiveTailKeyBindingsTest(unittest.TestCase):
 class LiveTailKeyBindingsTest(unittest.TestCase):
     def setUp(self) -> None:
         self.ui = mock.Mock(InteractiveUI)
+        self.ui.highlight_term_in_buffer = mock.Mock()
+        self.ui.remove_term_from_buffer = mock.Mock()
         self.prompt_buffer = Buffer()
         self.output_buffer = Buffer()
         self.ui._application = mock.Mock(Application)
