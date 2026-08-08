--- tests/unit/autocomplete/local/test_indexer.py.orig	2026-02-27 19:05:56 UTC
+++ tests/unit/autocomplete/local/test_indexer.py
@@ -237,7 +237,7 @@ class TestGeneratesIndex(BaseIndexerTest):
 
     def test_generates_indexes_for_tables(self):
         self.indexer.generate_index(self.aws_command)
-        index_info = 'SELECT name from pragma_index_info("%s");'
+        index_info = "SELECT name from pragma_index_info('%s');"
         index = self.db_conn.execute(index_info % 'parent_index').fetchall()
         self.assertEqual([('parent',)], index)
         index = self.db_conn.execute(
