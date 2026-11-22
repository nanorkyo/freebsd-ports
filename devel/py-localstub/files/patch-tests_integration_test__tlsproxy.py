--- tests/integration/test_tlsproxy.py.orig	2020-02-02 00:00:00 UTC
+++ tests/integration/test_tlsproxy.py
@@ -2093,6 +2093,7 @@ async def test_proxy_records_request_and_response_when
             proxy=f"http://{proxy_host}:{proxy_port}",
             verify=verify_ctx,
             http2=False,
+            headers={"Accept-Encoding": "identity"},
         ) as client:
             response = await client.get("https://example.com/")
 
