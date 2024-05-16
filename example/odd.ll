; ModuleID = 'odd.ll'
source_filename = "odd.ll"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
main.entry.0:
  %0 = alloca i32, align 4
  store i32 0, ptr %0, align 4
  br label %while.condition.1

while.condition.1:                                ; preds = %if.out.5, %if.true.4, %main.entry.0
  %1 = load i32, ptr %0, align 4
  %2 = icmp slt i32 %1, 10
  br i1 %2, label %while.body.2, label %while.out.3

while.body.2:                                     ; preds = %while.condition.1
  %3 = load i32, ptr %0, align 4
  %4 = add i32 %3, 1
  store i32 %4, ptr %0, align 4
  %5 = load i32, ptr %0, align 4
  %6 = load i32, ptr %0, align 4
  %7 = srem i32 %6, 2
  %8 = icmp eq i32 %7, 0
  br i1 %8, label %if.true.4, label %if.out.5

while.out.3:                                      ; preds = %while.condition.1
  ret i32 0

if.true.4:                                        ; preds = %while.body.2
  br label %while.condition.1

if.out.5:                                         ; preds = %while.body.2
  %9 = load i32, ptr %0, align 4
  %10 = call i32 (ptr, ...) @printf(ptr @0, i32 %9)
  br label %while.condition.1
}

declare i32 @printf(ptr, ...)
