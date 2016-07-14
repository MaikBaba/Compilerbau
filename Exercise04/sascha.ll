; ModuleID = './sascha.cpp'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: norecurse nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i8, align 1
  store i32 0, i32* %1, align 4
  store i8 1, i8* %j, align 1
  store i32 1, i32* %i, align 4
  br label %2

; <label>:2                                       ; preds = %8, %0
  %3 = load i32, i32* %i, align 4
  %4 = load i8, i8* %j, align 1
  %5 = trunc i8 %4 to i1
  %6 = zext i1 %5 to i32
  %7 = icmp eq i32 %3, %6
  br i1 %7, label %8, label %9

; <label>:8                                       ; preds = %2
  store i32 0, i32* %i, align 4
  br label %2

; <label>:9                                       ; preds = %2
  br label %10

; <label>:10                                      ; preds = %16, %9
  %11 = load i32, i32* %i, align 4
  %12 = load i8, i8* %j, align 1
  %13 = trunc i8 %12 to i1
  %14 = zext i1 %13 to i32
  %15 = icmp ne i32 %11, %14
  br i1 %15, label %16, label %17

; <label>:16                                      ; preds = %10
  store i32 0, i32* %i, align 4
  br label %10

; <label>:17                                      ; preds = %10
  br label %18

; <label>:18                                      ; preds = %24, %17
  %19 = load i32, i32* %i, align 4
  %20 = load i8, i8* %j, align 1
  %21 = trunc i8 %20 to i1
  %22 = zext i1 %21 to i32
  %23 = icmp sgt i32 %19, %22
  br i1 %23, label %24, label %25

; <label>:24                                      ; preds = %18
  store i32 0, i32* %i, align 4
  br label %18

; <label>:25                                      ; preds = %18
  br label %26

; <label>:26                                      ; preds = %32, %25
  %27 = load i32, i32* %i, align 4
  %28 = load i8, i8* %j, align 1
  %29 = trunc i8 %28 to i1
  %30 = zext i1 %29 to i32
  %31 = icmp slt i32 %27, %30
  br i1 %31, label %32, label %33

; <label>:32                                      ; preds = %26
  store i32 0, i32* %i, align 4
  br label %26

; <label>:33                                      ; preds = %26
  br label %34

; <label>:34                                      ; preds = %40, %33
  %35 = load i32, i32* %i, align 4
  %36 = load i8, i8* %j, align 1
  %37 = trunc i8 %36 to i1
  %38 = zext i1 %37 to i32
  %39 = icmp sle i32 %35, %38
  br i1 %39, label %40, label %41

; <label>:40                                      ; preds = %34
  store i32 0, i32* %i, align 4
  br label %34

; <label>:41                                      ; preds = %34
  br label %42

; <label>:42                                      ; preds = %48, %41
  %43 = load i32, i32* %i, align 4
  %44 = load i8, i8* %j, align 1
  %45 = trunc i8 %44 to i1
  %46 = zext i1 %45 to i32
  %47 = icmp sge i32 %43, %46
  br i1 %47, label %48, label %49

; <label>:48                                      ; preds = %42
  store i32 0, i32* %i, align 4
  br label %42

; <label>:49                                      ; preds = %42
  %50 = load i32, i32* %i, align 4
  %51 = add nsw i32 %50, 1
  store i32 %51, i32* %i, align 4
  %52 = load i32, i32* %i, align 4
  %53 = load i32, i32* %i, align 4
  %54 = add nsw i32 %52, %53
  store i32 %54, i32* %i, align 4
  %55 = load i32, i32* %i, align 4
  %56 = load i8, i8* %j, align 1
  %57 = trunc i8 %56 to i1
  %58 = zext i1 %57 to i32
  %59 = add nsw i32 %55, %58
  store i32 %59, i32* %i, align 4
  %60 = load i32, i32* %i, align 4
  %61 = sub nsw i32 %60, 1
  store i32 %61, i32* %i, align 4
  %62 = load i32, i32* %i, align 4
  %63 = load i32, i32* %i, align 4
  %64 = sub nsw i32 %62, %63
  store i32 %64, i32* %i, align 4
  %65 = load i32, i32* %i, align 4
  %66 = load i8, i8* %j, align 1
  %67 = trunc i8 %66 to i1
  %68 = zext i1 %67 to i32
  %69 = sub nsw i32 %65, %68
  store i32 %69, i32* %i, align 4
  %70 = load i32, i32* %i, align 4
  %71 = mul nsw i32 %70, 1
  store i32 %71, i32* %i, align 4
  %72 = load i32, i32* %i, align 4
  %73 = load i32, i32* %i, align 4
  %74 = mul nsw i32 %72, %73
  store i32 %74, i32* %i, align 4
  %75 = load i32, i32* %i, align 4
  %76 = load i8, i8* %j, align 1
  %77 = trunc i8 %76 to i1
  %78 = zext i1 %77 to i32
  %79 = mul nsw i32 %75, %78
  store i32 %79, i32* %i, align 4
  %80 = load i32, i32* %i, align 4
  %81 = sdiv i32 %80, 1
  store i32 %81, i32* %i, align 4
  %82 = load i32, i32* %i, align 4
  %83 = load i32, i32* %i, align 4
  %84 = sdiv i32 %82, %83
  store i32 %84, i32* %i, align 4
  %85 = load i32, i32* %i, align 4
  %86 = load i8, i8* %j, align 1
  %87 = trunc i8 %86 to i1
  %88 = zext i1 %87 to i32
  %89 = sdiv i32 %85, %88
  store i32 %89, i32* %i, align 4
  ret i32 1
}

attributes #0 = { norecurse nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0-2ubuntu3 (tags/RELEASE_380/final)"}
