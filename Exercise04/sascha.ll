; ModuleID = './sascha.cpp'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: norecurse nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %i = alloca i8, align 1
  %j = alloca i8, align 1
  store i32 0, i32* %1, align 4
  store i8 1, i8* %j, align 1
  store i8 1, i8* %i, align 1
  br label %2

; <label>:2                                       ; preds = %10, %0
  %3 = load i8, i8* %i, align 1
  %4 = trunc i8 %3 to i1
  br i1 %4, label %8, label %5

; <label>:5                                       ; preds = %2
  %6 = load i8, i8* %j, align 1
  %7 = trunc i8 %6 to i1
  br label %8

; <label>:8                                       ; preds = %5, %2
  %9 = phi i1 [ true, %2 ], [ %7, %5 ]
  br i1 %9, label %10, label %11

; <label>:10                                      ; preds = %8
  store i8 0, i8* %i, align 1
  br label %2

; <label>:11                                      ; preds = %8
  br label %12

; <label>:12                                      ; preds = %20, %11
  %13 = load i8, i8* %i, align 1
  %14 = trunc i8 %13 to i1
  %15 = zext i1 %14 to i32
  %16 = load i8, i8* %j, align 1
  %17 = trunc i8 %16 to i1
  %18 = zext i1 %17 to i32
  %19 = icmp ne i32 %15, %18
  br i1 %19, label %20, label %21

; <label>:20                                      ; preds = %12
  store i8 0, i8* %i, align 1
  br label %12

; <label>:21                                      ; preds = %12
  br label %22

; <label>:22                                      ; preds = %30, %21
  %23 = load i8, i8* %i, align 1
  %24 = trunc i8 %23 to i1
  %25 = zext i1 %24 to i32
  %26 = load i8, i8* %j, align 1
  %27 = trunc i8 %26 to i1
  %28 = zext i1 %27 to i32
  %29 = icmp sgt i32 %25, %28
  br i1 %29, label %30, label %31

; <label>:30                                      ; preds = %22
  store i8 0, i8* %i, align 1
  br label %22

; <label>:31                                      ; preds = %22
  br label %32

; <label>:32                                      ; preds = %40, %31
  %33 = load i8, i8* %i, align 1
  %34 = trunc i8 %33 to i1
  %35 = zext i1 %34 to i32
  %36 = load i8, i8* %j, align 1
  %37 = trunc i8 %36 to i1
  %38 = zext i1 %37 to i32
  %39 = icmp slt i32 %35, %38
  br i1 %39, label %40, label %41

; <label>:40                                      ; preds = %32
  store i8 0, i8* %i, align 1
  br label %32

; <label>:41                                      ; preds = %32
  br label %42

; <label>:42                                      ; preds = %50, %41
  %43 = load i8, i8* %i, align 1
  %44 = trunc i8 %43 to i1
  %45 = zext i1 %44 to i32
  %46 = load i8, i8* %j, align 1
  %47 = trunc i8 %46 to i1
  %48 = zext i1 %47 to i32
  %49 = icmp sle i32 %45, %48
  br i1 %49, label %50, label %51

; <label>:50                                      ; preds = %42
  store i8 0, i8* %i, align 1
  br label %42

; <label>:51                                      ; preds = %42
  br label %52

; <label>:52                                      ; preds = %60, %51
  %53 = load i8, i8* %i, align 1
  %54 = trunc i8 %53 to i1
  %55 = zext i1 %54 to i32
  %56 = load i8, i8* %j, align 1
  %57 = trunc i8 %56 to i1
  %58 = zext i1 %57 to i32
  %59 = icmp sge i32 %55, %58
  br i1 %59, label %60, label %61

; <label>:60                                      ; preds = %52
  store i8 0, i8* %i, align 1
  br label %52

; <label>:61                                      ; preds = %52
  %62 = load i8, i8* %i, align 1
  %63 = trunc i8 %62 to i1
  %64 = zext i1 %63 to i32
  %65 = add nsw i32 %64, 1
  %66 = icmp ne i32 %65, 0
  %67 = zext i1 %66 to i8
  store i8 %67, i8* %i, align 1
  %68 = load i8, i8* %i, align 1
  %69 = trunc i8 %68 to i1
  %70 = zext i1 %69 to i32
  %71 = load i8, i8* %i, align 1
  %72 = trunc i8 %71 to i1
  %73 = zext i1 %72 to i32
  %74 = add nsw i32 %70, %73
  %75 = icmp ne i32 %74, 0
  %76 = zext i1 %75 to i8
  store i8 %76, i8* %i, align 1
  %77 = load i8, i8* %i, align 1
  %78 = trunc i8 %77 to i1
  %79 = zext i1 %78 to i32
  %80 = load i8, i8* %j, align 1
  %81 = trunc i8 %80 to i1
  %82 = zext i1 %81 to i32
  %83 = add nsw i32 %79, %82
  %84 = icmp ne i32 %83, 0
  %85 = zext i1 %84 to i8
  store i8 %85, i8* %i, align 1
  %86 = load i8, i8* %i, align 1
  %87 = trunc i8 %86 to i1
  %88 = zext i1 %87 to i32
  %89 = sub nsw i32 %88, 1
  %90 = icmp ne i32 %89, 0
  %91 = zext i1 %90 to i8
  store i8 %91, i8* %i, align 1
  %92 = load i8, i8* %i, align 1
  %93 = trunc i8 %92 to i1
  %94 = zext i1 %93 to i32
  %95 = load i8, i8* %i, align 1
  %96 = trunc i8 %95 to i1
  %97 = zext i1 %96 to i32
  %98 = sub nsw i32 %94, %97
  %99 = icmp ne i32 %98, 0
  %100 = zext i1 %99 to i8
  store i8 %100, i8* %i, align 1
  %101 = load i8, i8* %i, align 1
  %102 = trunc i8 %101 to i1
  %103 = zext i1 %102 to i32
  %104 = load i8, i8* %j, align 1
  %105 = trunc i8 %104 to i1
  %106 = zext i1 %105 to i32
  %107 = sub nsw i32 %103, %106
  %108 = icmp ne i32 %107, 0
  %109 = zext i1 %108 to i8
  store i8 %109, i8* %i, align 1
  %110 = load i8, i8* %i, align 1
  %111 = trunc i8 %110 to i1
  %112 = zext i1 %111 to i32
  %113 = mul nsw i32 %112, 1
  %114 = icmp ne i32 %113, 0
  %115 = zext i1 %114 to i8
  store i8 %115, i8* %i, align 1
  %116 = load i8, i8* %i, align 1
  %117 = trunc i8 %116 to i1
  %118 = zext i1 %117 to i32
  %119 = load i8, i8* %i, align 1
  %120 = trunc i8 %119 to i1
  %121 = zext i1 %120 to i32
  %122 = mul nsw i32 %118, %121
  %123 = icmp ne i32 %122, 0
  %124 = zext i1 %123 to i8
  store i8 %124, i8* %i, align 1
  %125 = load i8, i8* %i, align 1
  %126 = trunc i8 %125 to i1
  %127 = zext i1 %126 to i32
  %128 = load i8, i8* %j, align 1
  %129 = trunc i8 %128 to i1
  %130 = zext i1 %129 to i32
  %131 = mul nsw i32 %127, %130
  %132 = icmp ne i32 %131, 0
  %133 = zext i1 %132 to i8
  store i8 %133, i8* %i, align 1
  %134 = load i8, i8* %i, align 1
  %135 = trunc i8 %134 to i1
  %136 = zext i1 %135 to i32
  %137 = sdiv i32 %136, 1
  %138 = icmp ne i32 %137, 0
  %139 = zext i1 %138 to i8
  store i8 %139, i8* %i, align 1
  %140 = load i8, i8* %i, align 1
  %141 = trunc i8 %140 to i1
  %142 = zext i1 %141 to i32
  %143 = load i8, i8* %i, align 1
  %144 = trunc i8 %143 to i1
  %145 = zext i1 %144 to i32
  %146 = sdiv i32 %142, %145
  %147 = icmp ne i32 %146, 0
  %148 = zext i1 %147 to i8
  store i8 %148, i8* %i, align 1
  %149 = load i8, i8* %i, align 1
  %150 = trunc i8 %149 to i1
  %151 = zext i1 %150 to i32
  %152 = load i8, i8* %j, align 1
  %153 = trunc i8 %152 to i1
  %154 = zext i1 %153 to i32
  %155 = sdiv i32 %151, %154
  %156 = icmp ne i32 %155, 0
  %157 = zext i1 %156 to i8
  store i8 %157, i8* %i, align 1
  ret i32 1
}

attributes #0 = { norecurse nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0-2ubuntu3 (tags/RELEASE_380/final)"}
