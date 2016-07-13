; ModuleID = 'good.cpp'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: uwtable
define i32 @_Z5factri(i32 %n) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %a = alloca double, align 8
  store i32 %n, i32* %2, align 4
  store double 6.500000e+01, double* %a, align 8
  %3 = load double, double* %a, align 8
  %4 = fadd double %3, 1.000000e+00
  store double %4, double* %a, align 8
  %5 = load double, double* %a, align 8
  %6 = fcmp une double %5, 0.000000e+00
  br i1 %6, label %7, label %8

; <label>:7                                       ; preds = %0
  store i32 1, i32* %1, align 4
  br label %14

; <label>:8                                       ; preds = %0
  %9 = load i32, i32* %2, align 4
  %10 = load i32, i32* %2, align 4
  %11 = sub nsw i32 %10, 1
  %12 = call i32 @_Z5factri(i32 %11)
  %13 = mul nsw i32 %9, %12
  store i32 %13, i32* %1, align 4
  br label %14

; <label>:14                                      ; preds = %8, %7
  %15 = load i32, i32* %1, align 4
  ret i32 %15
}

; Function Attrs: norecurse uwtable
define i32 @main() #1 {
  %1 = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 @_Z5factri(i32 7)
  store i32 %2, i32* %i, align 4
  br label %3

; <label>:3                                       ; preds = %6, %0
  %4 = load i32, i32* %i, align 4
  %5 = icmp eq i32 %4, 1
  br i1 %5, label %6, label %7

; <label>:6                                       ; preds = %3
  store i32 0, i32* %i, align 4
  br label %3

; <label>:7                                       ; preds = %3
  ret i32 0
}

attributes #0 = { uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { norecurse uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0-2ubuntu3 (tags/RELEASE_380/final)"}
