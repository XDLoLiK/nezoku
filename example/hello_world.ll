; ModuleID = 'hello_world.ll'
source_filename = "hello_world.ll"

@0 = private unnamed_addr constant [15 x i8] c"Hello, World!\0A\00", align 1

define i32 @main() {
main.entry.0:
  %0 = call i32 (ptr, ...) @printf(ptr @0)
  ret i32 0
}

declare i32 @printf(ptr, ...)
