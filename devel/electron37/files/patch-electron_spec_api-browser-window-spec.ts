--- electron/spec/api-browser-window-spec.ts.orig	2025-07-09 10:31:48 UTC
+++ electron/spec/api-browser-window-spec.ts
@@ -69,7 +69,7 @@ describe('BrowserWindow module', () => {
       }).not.to.throw();
     });
 
-    ifit(process.platform === 'linux')('does not crash when setting large window icons', async () => {
+    ifit(process.platform === 'linux' || process.platform === 'freebsd')('does not crash when setting large window icons', async () => {
       const appPath = path.join(fixtures, 'apps', 'xwindow-icon');
       const appProcess = childProcess.spawn(process.execPath, [appPath]);
       await once(appProcess, 'exit');
@@ -296,7 +296,7 @@ describe('BrowserWindow module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('BrowserWindow.getContentProtection', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('BrowserWindow.getContentProtection', () => {
     afterEach(closeAllWindows);
     it('can set content protection', async () => {
       const w = new BrowserWindow({ show: false });
@@ -1167,7 +1167,7 @@ describe('BrowserWindow module', () => {
 
     describe('BrowserWindow.minimize()', () => {
       // TODO(codebytere): Enable for Linux once maximize/minimize events work in CI.
-      ifit(process.platform !== 'linux')('should not be visible when the window is minimized', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not be visible when the window is minimized', async () => {
         const minimize = once(w, 'minimize');
         w.minimize();
         await minimize;
@@ -1184,7 +1184,7 @@ describe('BrowserWindow module', () => {
       });
 
       // TODO(dsanders11): Enable for Linux once CI plays nice with these kinds of tests
-      ifit(process.platform !== 'linux')('should not restore maximized windows', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not restore maximized windows', async () => {
         const maximize = once(w, 'maximize');
         const shown = once(w, 'show');
         w.maximize();
@@ -1249,7 +1249,7 @@ describe('BrowserWindow module', () => {
         expect(w.isFocused()).to.equal(true);
       });
 
-      ifit(process.platform !== 'linux')('acquires focus status from the other windows', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('acquires focus status from the other windows', async () => {
         const w1 = new BrowserWindow({ show: false });
         const w2 = new BrowserWindow({ show: false });
         const w3 = new BrowserWindow({ show: false });
@@ -1351,7 +1351,7 @@ describe('BrowserWindow module', () => {
         expect(w.isFocused()).to.equal(false);
       });
 
-      ifit(process.platform !== 'linux')('transfers focus status to the next window', async () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('transfers focus status to the next window', async () => {
         const w1 = new BrowserWindow({ show: false });
         const w2 = new BrowserWindow({ show: false });
         const w3 = new BrowserWindow({ show: false });
@@ -1810,7 +1810,7 @@ describe('BrowserWindow module', () => {
         });
       });
 
-      ifdescribe(process.platform !== 'linux')('Maximized state', () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('Maximized state', () => {
         it('checks normal bounds when maximized', async () => {
           const bounds = w.getBounds();
           const maximize = once(w, 'maximize');
@@ -2020,7 +2020,7 @@ describe('BrowserWindow module', () => {
         });
       });
 
-      ifdescribe(process.platform !== 'linux')('Minimized state', () => {
+      ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('Minimized state', () => {
         it('checks normal bounds when minimized', async () => {
           const bounds = w.getBounds();
           const minimize = once(w, 'minimize');
@@ -2984,7 +2984,7 @@ describe('BrowserWindow module', () => {
   describe('BrowserWindow.setOpacity(opacity)', () => {
     afterEach(closeAllWindows);
 
-    ifdescribe(process.platform !== 'linux')(('Windows and Mac'), () => {
+    ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')(('Windows and Mac'), () => {
       it('make window with initial opacity', () => {
         const w = new BrowserWindow({ show: false, opacity: 0.5 });
         expect(w.getOpacity()).to.equal(0.5);
@@ -3010,7 +3010,7 @@ describe('BrowserWindow module', () => {
       });
     });
 
-    ifdescribe(process.platform === 'linux')(('Linux'), () => {
+    ifdescribe(process.platform === 'linux' || process.platform === 'freebsd')(('Linux'), () => {
       it('sets 1 regardless of parameter', () => {
         const w = new BrowserWindow({ show: false });
         w.setOpacity(0);
@@ -3221,7 +3221,7 @@ describe('BrowserWindow module', () => {
       expect(overlayRectPreMax.height).to.equal(size);
 
       // 'maximize' event is not emitted on Linux in CI.
-      if (process.platform !== 'linux' && !w.isMaximized()) {
+      if ((process.platform !== 'linux' && process.platform !== 'freebsd') && !w.isMaximized()) {
         const maximize = once(w, 'maximize');
         w.show();
         w.maximize();
@@ -3287,7 +3287,7 @@ describe('BrowserWindow module', () => {
         expect(preMaxHeight).to.equal(size);
 
         // 'maximize' event is not emitted on Linux in CI.
-        if (process.platform !== 'linux' && !w.isMaximized()) {
+        if ((process.platform !== 'linux' && process.platform !== 'freebsd') && !w.isMaximized()) {
           const maximize = once(w, 'maximize');
           w.show();
           w.maximize();
@@ -3952,7 +3952,7 @@ describe('BrowserWindow module', () => {
         expect(test.nodeTimers).to.equal(true);
         expect(test.nodeUrl).to.equal(true);
 
-        if (process.platform === 'linux' && test.osSandbox) {
+        if ((process.platform === 'linux' || process.platform === 'freebsd') && test.osSandbox) {
           expect(test.creationTime).to.be.null('creation time');
           expect(test.systemMemoryInfo).to.be.null('system memory info');
         } else {
@@ -4457,7 +4457,7 @@ describe('BrowserWindow module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('max/minimize events', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('max/minimize events', () => {
     afterEach(closeAllWindows);
     it('emits an event when window is maximized', async () => {
       const w = new BrowserWindow({ show: false });
@@ -4728,7 +4728,7 @@ describe('BrowserWindow module', () => {
     // TODO(zcbenz):
     // This test does not run on Linux CI. See:
     // https://github.com/electron/electron/issues/28699
-    ifit(process.platform === 'linux' && !process.env.CI)('should bring a minimized maximized window back to maximized state', async () => {
+    ifit((process.platform === 'linux' || process.platform === 'freebsd') && !process.env.CI)('should bring a minimized maximized window back to maximized state', async () => {
       const w = new BrowserWindow({});
       const maximize = once(w, 'maximize');
       w.maximize();
@@ -4745,7 +4745,7 @@ describe('BrowserWindow module', () => {
   });
 
   // TODO(dsanders11): Enable once maximize event works on Linux again on CI
-  ifdescribe(process.platform !== 'linux')('BrowserWindow.maximize()', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('BrowserWindow.maximize()', () => {
     afterEach(closeAllWindows);
     it('should show the window if it is not currently shown', async () => {
       const w = new BrowserWindow({ show: false });
@@ -4782,7 +4782,7 @@ describe('BrowserWindow module', () => {
 
     // TODO(dsanders11): Enable once minimize event works on Linux again.
     //                   See https://github.com/electron/electron/issues/28699
-    ifit(process.platform !== 'linux')('should not restore a minimized window', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('should not restore a minimized window', async () => {
       const w = new BrowserWindow();
       const minimize = once(w, 'minimize');
       w.minimize();
@@ -5268,7 +5268,7 @@ describe('BrowserWindow module', () => {
       });
 
       // On Linux there is no "resizable" property of a window.
-      ifit(process.platform !== 'linux')('does affect maximizability when disabled and enabled', () => {
+      ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('does affect maximizability when disabled and enabled', () => {
         const w = new BrowserWindow({ show: false });
         expect(w.resizable).to.be.true('resizable');
 
@@ -5478,7 +5478,7 @@ describe('BrowserWindow module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('window states (excluding Linux)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('window states (excluding Linux)', () => {
     // Not implemented on Linux.
     afterEach(closeAllWindows);
 
@@ -6725,7 +6725,7 @@ describe('BrowserWindow module', () => {
   describe('"transparent" option', () => {
     afterEach(closeAllWindows);
 
-    ifit(process.platform !== 'linux')('correctly returns isMaximized() when the window is maximized then minimized', async () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('correctly returns isMaximized() when the window is maximized then minimized', async () => {
       const w = new BrowserWindow({
         frame: false,
         transparent: true
