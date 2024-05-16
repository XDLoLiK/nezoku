; ModuleID = 'factorial.ll'
source_filename = "factorial.ll"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @factorial(i32 %0) {
factorial.entry.0:
  %1 = alloca i32, align 4
  store i32 %0, ptr %1, align 4
  %2 = load i32, ptr %1, align 4
  %3 = icmp eq i32 %2, 0
  br i1 %3, label %if.true.1, label %if.out.2

if.true.1:                                        ; preds = %factorial.entry.0
  ret i32 1

if.out.2:                                         ; preds = %factorial.entry.0
  %4 = load i32, ptr %1, align 4
  %5 = load i32, ptr %1, align 4
  %6 = sub i32 %5, 1
  %7 = call i32 @factorial(i32 %6)
  %8 = mul i32 %4, %7
  ret i32 %8
}

define i32 @main() {
main.entry.3:
  %0 = alloca i32, align 4
  store i32 5, ptr %0, align 4
  %1 = alloca i32, align 4
  %2 = load i32, ptr %0, align 4
  %3 = call i32 @factorial(i32 %2)
  store i32 %3, ptr %1, align 4
  %4 = load i32, ptr %1, align 4
  %5 = call i32 (ptr, ...) @printf(ptr @0, i32 %4)
  ret i32 0
}

declare i32 @printf(ptr, ...)
