--- src/3rdparty/chromium/v8/src/wasm/baseline/ia32/liftoff-assembler-ia32-inl.h.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/v8/src/wasm/baseline/ia32/liftoff-assembler-ia32-inl.h
@@ -512,7 +512,7 @@ void LiftoffAssembler::StoreTaggedPointer(Register dst
 }
 
 void LiftoffAssembler::Load(LiftoffRegister dst, Register src_addr,
-                            Register offset_reg, uint32_t offset_imm,
+                            Register offset_reg, uintptr_t offset_imm,
                             LoadType type, uint32_t* protected_load_pc,
                             bool /* is_load_mem */, bool /* i64_offset */,
                             bool needs_shift) {
@@ -592,7 +592,7 @@ void LiftoffAssembler::Load(LiftoffRegister dst, Regis
 }
 
 void LiftoffAssembler::Store(Register dst_addr, Register offset_reg,
-                             uint32_t offset_imm, LiftoffRegister src,
+                             uintptr_t offset_imm, LiftoffRegister src,
                              StoreType type, LiftoffRegList pinned,
                              uint32_t* protected_store_pc,
                              bool /* is_store_mem */, bool /* i64_offset */) {
@@ -671,7 +671,7 @@ void LiftoffAssembler::Store(Register dst_addr, Regist
 }
 
 void LiftoffAssembler::AtomicLoad(LiftoffRegister dst, Register src_addr,
-                                  Register offset_reg, uint32_t offset_imm,
+                                  Register offset_reg, uintptr_t offset_imm,
                                   LoadType type, LiftoffRegList /* pinned */,
                                   bool /* i64_offset */) {
   if (type.value() != LoadType::kI64Load) {
@@ -689,7 +689,7 @@ void LiftoffAssembler::AtomicLoad(LiftoffRegister dst,
 }
 
 void LiftoffAssembler::AtomicStore(Register dst_addr, Register offset_reg,
-                                   uint32_t offset_imm, LiftoffRegister src,
+                                   uintptr_t offset_imm, LiftoffRegister src,
                                    StoreType type, LiftoffRegList pinned,
                                    bool /* i64_offset */) {
   DCHECK_LE(offset_imm, std::numeric_limits<int32_t>::max());
@@ -759,7 +759,7 @@ enum Binop { kAdd, kSub, kAnd, kOr, kXor, kExchange };
 
 inline void AtomicAddOrSubOrExchange32(LiftoffAssembler* lasm, Binop binop,
                                        Register dst_addr, Register offset_reg,
-                                       uint32_t offset_imm,
+                                       uintptr_t offset_imm,
                                        LiftoffRegister value,
                                        LiftoffRegister result, StoreType type) {
   DCHECK_EQ(value, result);
@@ -827,7 +827,7 @@ inline void AtomicAddOrSubOrExchange32(LiftoffAssemble
 }
 
 inline void AtomicBinop32(LiftoffAssembler* lasm, Binop op, Register dst_addr,
-                          Register offset_reg, uint32_t offset_imm,
+                          Register offset_reg, uintptr_t offset_imm,
                           LiftoffRegister value, LiftoffRegister result,
                           StoreType type) {
   DCHECK_EQ(value, result);
@@ -942,7 +942,7 @@ inline void AtomicBinop32(LiftoffAssembler* lasm, Bino
 }
 
 inline void AtomicBinop64(LiftoffAssembler* lasm, Binop op, Register dst_addr,
-                          Register offset_reg, uint32_t offset_imm,
+                          Register offset_reg, uintptr_t offset_imm,
                           LiftoffRegister value, LiftoffRegister result) {
   // We need {ebx} here, which is the root register. As the root register it
   // needs special treatment. As we use {ebx} directly in the code below, we
@@ -1038,7 +1038,7 @@ inline void AtomicBinop64(LiftoffAssembler* lasm, Bino
 }  // namespace liftoff
 
 void LiftoffAssembler::AtomicAdd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1052,7 +1052,7 @@ void LiftoffAssembler::AtomicAdd(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicSub(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1065,7 +1065,7 @@ void LiftoffAssembler::AtomicSub(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicAnd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1079,7 +1079,7 @@ void LiftoffAssembler::AtomicAnd(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicOr(Register dst_addr, Register offset_reg,
-                                uint32_t offset_imm, LiftoffRegister value,
+                                uintptr_t offset_imm, LiftoffRegister value,
                                 LiftoffRegister result, StoreType type,
                                 bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1093,7 +1093,7 @@ void LiftoffAssembler::AtomicOr(Register dst_addr, Reg
 }
 
 void LiftoffAssembler::AtomicXor(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type,
                                  bool /* i64_offset */) {
   if (type.value() == StoreType::kI64Store) {
@@ -1107,7 +1107,7 @@ void LiftoffAssembler::AtomicXor(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicExchange(Register dst_addr, Register offset_reg,
-                                      uint32_t offset_imm,
+                                      uintptr_t offset_imm,
                                       LiftoffRegister value,
                                       LiftoffRegister result, StoreType type,
                                       bool /* i64_offset */) {
@@ -1122,7 +1122,7 @@ void LiftoffAssembler::AtomicExchange(Register dst_add
 }
 
 void LiftoffAssembler::AtomicCompareExchange(
-    Register dst_addr, Register offset_reg, uint32_t offset_imm,
+    Register dst_addr, Register offset_reg, uintptr_t offset_imm,
     LiftoffRegister expected, LiftoffRegister new_value, LiftoffRegister result,
     StoreType type, bool /* i64_offset */) {
   // We expect that the offset has already been added to {dst_addr}, and no
