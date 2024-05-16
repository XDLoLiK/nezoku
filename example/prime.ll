; ModuleID = 'prime.ll'
source_filename = "prime.ll"

@0 = private unnamed_addr constant [17 x i8] c"%d is not prime\0A\00", align 1
@1 = private unnamed_addr constant [13 x i8] c"%d is prime\0A\00", align 1
@2 = private unnamed_addr constant [17 x i8] c"%d is not prime\0A\00", align 1

define i32 @main(i32 %0) {
main.entry.0:
  %1 = alloca i32, align 4
  store i32 %0, ptr %1, align 4
  %2 = alloca i32, align 4
  store i32 0, ptr %2, align 4
  %3 = alloca i32, align 4
  br label %while.condition.1

while.condition.1:                                ; preds = %if.out.12, %if.true.4, %main.entry.0
  %4 = load i32, ptr %2, align 4
  %5 = icmp slt i32 %4, 100
  br i1 %5, label %while.body.2, label %while.out.3

while.body.2:                                     ; preds = %while.condition.1
  %6 = load i32, ptr %2, align 4
  %7 = add i32 %6, 1
  store i32 %7, ptr %2, align 4
  %8 = load i32, ptr %2, align 4
  store i32 3, ptr %3, align 4
  %9 = load i32, ptr %3, align 4
  %10 = load i32, ptr %2, align 4
  %11 = srem i32 %10, 2
  %12 = icmp eq i32 %11, 0
  br i1 %12, label %if.true.4, label %if.out.5

while.out.3:                                      ; preds = %while.condition.1
  ret i32 0

if.true.4:                                        ; preds = %while.body.2
  %13 = load i32, ptr %2, align 4
  %14 = call i32 (ptr, ...) @printf(ptr @0, i32 %13)
  br label %while.condition.1

if.out.5:                                         ; preds = %while.body.2
  %15 = alloca i32, align 4
  store i32 1, ptr %15, align 4
  br label %while.condition.6

while.condition.6:                                ; preds = %if.out.10, %if.out.5
  %16 = load i32, ptr %3, align 4
  %17 = load i32, ptr %2, align 4
  %18 = icmp slt i32 %16, %17
  br i1 %18, label %while.body.7, label %while.out.8

while.body.7:                                     ; preds = %while.condition.6
  %19 = load i32, ptr %2, align 4
  %20 = load i32, ptr %3, align 4
  %21 = srem i32 %19, %20
  %22 = icmp eq i32 %21, 0
  br i1 %22, label %if.true.9, label %if.out.10

while.out.8:                                      ; preds = %if.true.9, %while.condition.6
  %23 = load i32, ptr %15, align 4
  %24 = icmp eq i32 %23, 1
  br i1 %24, label %if.true.11, label %if.false.13

if.true.9:                                        ; preds = %while.body.7
  store i32 0, ptr %15, align 4
  %25 = load i32, ptr %15, align 4
  br label %while.out.8

if.out.10:                                        ; preds = %while.body.7
  %26 = load i32, ptr %3, align 4
  %27 = add i32 %26, 1
  store i32 %27, ptr %3, align 4
  %28 = load i32, ptr %3, align 4
  br label %while.condition.6

if.true.11:                                       ; preds = %while.out.8
  %29 = load i32, ptr %2, align 4
  %30 = call i32 (ptr, ...) @printf(ptr @1, i32 %29)
  br label %if.out.12

if.out.12:                                        ; preds = %if.false.13, %if.true.11
  br label %while.condition.1

if.false.13:                                      ; preds = %while.out.8
  %31 = load i32, ptr %2, align 4
  %32 = call i32 (ptr, ...) @printf(ptr @2, i32 %31)
  br label %if.out.12
}

declare i32 @printf(ptr, ...)
