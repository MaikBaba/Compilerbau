; ModuleID = 'test.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @_Z5factri(i32 %n) #0 {
  %1 = alloca i32, align 4
  %a = alloca double, align 8
  %b = alloca double, align 8
  %x = alloca i32, align 4
  store i32 %n, i32* %1, align 4
  store double 6.500000e+01, double* %a, align 8
  store double 1.000200e+02, double* %b, align 8
  store i32 10, i32* %x, align 4
  store double 1.000000e+01, double* %a, align 8
  %2 = load double, double* %a, align 8
  %3 = fadd double %2, 1.000000e+00
  store double %3, double* %a, align 8
  %4 = load double, double* %a, align 8
  %5 = fadd double %4, -1.000000e+00
  store double %5, double* %a, align 8
  %6 = load i32, i32* %x, align 4
  ret i32 %6
}

; Function Attrs: norecurse nounwind uwtable
define i32 @main() #1 {
  %1 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %d = alloca double, align 8
  %b = alloca i8, align 1
  store i32 0, i32* %1, align 4
  store i32 1, i32* %j, align 4
  store double 1.000000e+00, double* %d, align 8
  store i8 1, i8* %b, align 1
  store i32 1, i32* %i, align 4
  br label %2

; <label>:2                                       ; preds = %8, %0
  %3 = load i32, i32* %i, align 4
  %4 = sitofp i32 %3 to double
  %5 = load double, double* %d, align 8
  %6 = fadd double %5, 1.000000e+00
  store double %6, double* %d, align 8
  %7 = fcmp oeq double %4, %5
  br i1 %7, label %8, label %9

; <label>:8                                       ; preds = %2
  store i32 1, i32* %i, align 4
  br label %2

; <label>:9                                       ; preds = %2
  %10 = load i32, i32* %j, align 4
  %11 = icmp ne i32 %10, 0
  br i1 %11, label %12, label %13

; <label>:12                                      ; preds = %9
  store i32 2, i32* %i, align 4
  br label %14

; <label>:13                                      ; preds = %9
  br label %14

; <label>:14                                      ; preds = %13, %12
  %15 = load i32, i32* %i, align 4
  ret i32 %15
}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { norecurse nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0-2ubuntu3 (tags/RELEASE_380/final)"}
