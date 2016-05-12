{-# OPTIONS_GHC -w #-}
{-# OPTIONS_GHC -fno-warn-incomplete-patterns -fno-warn-overlapping-patterns #-}
module ParCPP where
import AbsCPP
import LexCPP
import ErrM
import Control.Applicative(Applicative(..))
import Control.Monad (ap)

-- parser produced by Happy Version 1.19.5

data HappyAbsSyn 
	= HappyTerminal (Token)
	| HappyErrorToken Int
	| HappyAbsSyn30 (Integer)
	| HappyAbsSyn31 (Double)
	| HappyAbsSyn32 (String)
	| HappyAbsSyn33 (Id)
	| HappyAbsSyn34 (Program)
	| HappyAbsSyn35 (Def)
	| HappyAbsSyn36 ([Def])
	| HappyAbsSyn37 ([Stm])
	| HappyAbsSyn38 ([Arg])
	| HappyAbsSyn39 ([Id])
	| HappyAbsSyn40 (Type)
	| HappyAbsSyn41 (Stm)
	| HappyAbsSyn42 (Arg)
	| HappyAbsSyn43 (Exp)
	| HappyAbsSyn60 ([Exp])

{- to allow type-synonyms as our monads (likely
 - with explicitly-specified bind and return)
 - in Haskell98, it seems that with
 - /type M a = .../, then /(HappyReduction M)/
 - is not allowed.  But Happy is a
 - code-generator that can just substitute it.
type HappyReduction m = 
	   Int 
	-> (Token)
	-> HappyState (Token) (HappyStk HappyAbsSyn -> [(Token)] -> m HappyAbsSyn)
	-> [HappyState (Token) (HappyStk HappyAbsSyn -> [(Token)] -> m HappyAbsSyn)] 
	-> HappyStk HappyAbsSyn 
	-> [(Token)] -> m HappyAbsSyn
-}

action_0,
 action_1,
 action_2,
 action_3,
 action_4,
 action_5,
 action_6,
 action_7,
 action_8,
 action_9,
 action_10,
 action_11,
 action_12,
 action_13,
 action_14,
 action_15,
 action_16,
 action_17,
 action_18,
 action_19,
 action_20,
 action_21,
 action_22,
 action_23,
 action_24,
 action_25,
 action_26,
 action_27,
 action_28,
 action_29,
 action_30,
 action_31,
 action_32,
 action_33,
 action_34,
 action_35,
 action_36,
 action_37,
 action_38,
 action_39,
 action_40,
 action_41,
 action_42,
 action_43,
 action_44,
 action_45,
 action_46,
 action_47,
 action_48,
 action_49,
 action_50,
 action_51,
 action_52,
 action_53,
 action_54,
 action_55,
 action_56,
 action_57,
 action_58,
 action_59,
 action_60,
 action_61,
 action_62,
 action_63,
 action_64,
 action_65,
 action_66,
 action_67,
 action_68,
 action_69,
 action_70,
 action_71,
 action_72,
 action_73,
 action_74,
 action_75,
 action_76,
 action_77,
 action_78,
 action_79,
 action_80,
 action_81,
 action_82,
 action_83,
 action_84,
 action_85,
 action_86,
 action_87,
 action_88,
 action_89,
 action_90,
 action_91,
 action_92,
 action_93,
 action_94,
 action_95,
 action_96,
 action_97,
 action_98,
 action_99,
 action_100,
 action_101,
 action_102,
 action_103,
 action_104,
 action_105,
 action_106,
 action_107,
 action_108,
 action_109,
 action_110,
 action_111,
 action_112,
 action_113,
 action_114,
 action_115,
 action_116,
 action_117,
 action_118,
 action_119,
 action_120,
 action_121,
 action_122,
 action_123,
 action_124,
 action_125,
 action_126,
 action_127,
 action_128,
 action_129,
 action_130,
 action_131,
 action_132,
 action_133,
 action_134,
 action_135,
 action_136,
 action_137,
 action_138,
 action_139,
 action_140,
 action_141,
 action_142,
 action_143,
 action_144,
 action_145,
 action_146,
 action_147,
 action_148,
 action_149,
 action_150,
 action_151,
 action_152,
 action_153,
 action_154,
 action_155,
 action_156,
 action_157,
 action_158,
 action_159,
 action_160,
 action_161,
 action_162,
 action_163,
 action_164,
 action_165,
 action_166,
 action_167,
 action_168,
 action_169,
 action_170,
 action_171,
 action_172,
 action_173,
 action_174,
 action_175,
 action_176,
 action_177,
 action_178,
 action_179,
 action_180,
 action_181,
 action_182,
 action_183,
 action_184,
 action_185,
 action_186,
 action_187,
 action_188,
 action_189,
 action_190,
 action_191,
 action_192,
 action_193,
 action_194,
 action_195,
 action_196,
 action_197,
 action_198,
 action_199,
 action_200,
 action_201,
 action_202,
 action_203,
 action_204,
 action_205 :: () => Int -> ({-HappyReduction (Err) = -}
	   Int 
	-> (Token)
	-> HappyState (Token) (HappyStk HappyAbsSyn -> [(Token)] -> (Err) HappyAbsSyn)
	-> [HappyState (Token) (HappyStk HappyAbsSyn -> [(Token)] -> (Err) HappyAbsSyn)] 
	-> HappyStk HappyAbsSyn 
	-> [(Token)] -> (Err) HappyAbsSyn)

happyReduce_27,
 happyReduce_28,
 happyReduce_29,
 happyReduce_30,
 happyReduce_31,
 happyReduce_32,
 happyReduce_33,
 happyReduce_34,
 happyReduce_35,
 happyReduce_36,
 happyReduce_37,
 happyReduce_38,
 happyReduce_39,
 happyReduce_40,
 happyReduce_41,
 happyReduce_42,
 happyReduce_43,
 happyReduce_44,
 happyReduce_45,
 happyReduce_46,
 happyReduce_47,
 happyReduce_48,
 happyReduce_49,
 happyReduce_50,
 happyReduce_51,
 happyReduce_52,
 happyReduce_53,
 happyReduce_54,
 happyReduce_55,
 happyReduce_56,
 happyReduce_57,
 happyReduce_58,
 happyReduce_59,
 happyReduce_60,
 happyReduce_61,
 happyReduce_62,
 happyReduce_63,
 happyReduce_64,
 happyReduce_65,
 happyReduce_66,
 happyReduce_67,
 happyReduce_68,
 happyReduce_69,
 happyReduce_70,
 happyReduce_71,
 happyReduce_72,
 happyReduce_73,
 happyReduce_74,
 happyReduce_75,
 happyReduce_76,
 happyReduce_77,
 happyReduce_78,
 happyReduce_79,
 happyReduce_80,
 happyReduce_81,
 happyReduce_82,
 happyReduce_83,
 happyReduce_84,
 happyReduce_85,
 happyReduce_86,
 happyReduce_87,
 happyReduce_88,
 happyReduce_89,
 happyReduce_90,
 happyReduce_91,
 happyReduce_92,
 happyReduce_93,
 happyReduce_94,
 happyReduce_95,
 happyReduce_96,
 happyReduce_97,
 happyReduce_98,
 happyReduce_99,
 happyReduce_100,
 happyReduce_101,
 happyReduce_102,
 happyReduce_103,
 happyReduce_104,
 happyReduce_105,
 happyReduce_106,
 happyReduce_107,
 happyReduce_108,
 happyReduce_109,
 happyReduce_110,
 happyReduce_111,
 happyReduce_112 :: () => ({-HappyReduction (Err) = -}
	   Int 
	-> (Token)
	-> HappyState (Token) (HappyStk HappyAbsSyn -> [(Token)] -> (Err) HappyAbsSyn)
	-> [HappyState (Token) (HappyStk HappyAbsSyn -> [(Token)] -> (Err) HappyAbsSyn)] 
	-> HappyStk HappyAbsSyn 
	-> [(Token)] -> (Err) HappyAbsSyn)

action_0 (34) = happyGoto action_104
action_0 (36) = happyGoto action_105
action_0 _ = happyReduce_33

action_1 (93) = happyShift action_83
action_1 (94) = happyShift action_84
action_1 (98) = happyShift action_85
action_1 (100) = happyShift action_86
action_1 (102) = happyShift action_87
action_1 (35) = happyGoto action_102
action_1 (40) = happyGoto action_103
action_1 _ = happyFail

action_2 (36) = happyGoto action_101
action_2 _ = happyReduce_33

action_3 (37) = happyGoto action_100
action_3 _ = happyReduce_35

action_4 (93) = happyShift action_83
action_4 (94) = happyShift action_84
action_4 (98) = happyShift action_85
action_4 (100) = happyShift action_86
action_4 (102) = happyShift action_87
action_4 (38) = happyGoto action_98
action_4 (40) = happyGoto action_81
action_4 (42) = happyGoto action_99
action_4 _ = happyReduce_37

action_5 (110) = happyShift action_61
action_5 (33) = happyGoto action_96
action_5 (39) = happyGoto action_97
action_5 _ = happyFail

action_6 (93) = happyShift action_83
action_6 (94) = happyShift action_84
action_6 (98) = happyShift action_85
action_6 (100) = happyShift action_86
action_6 (102) = happyShift action_87
action_6 (40) = happyGoto action_95
action_6 _ = happyFail

action_7 (62) = happyShift action_51
action_7 (66) = happyShift action_52
action_7 (68) = happyShift action_53
action_7 (70) = happyShift action_54
action_7 (73) = happyShift action_55
action_7 (74) = happyShift action_56
action_7 (93) = happyShift action_83
action_7 (94) = happyShift action_84
action_7 (96) = happyShift action_57
action_7 (97) = happyShift action_91
action_7 (98) = happyShift action_85
action_7 (99) = happyShift action_92
action_7 (100) = happyShift action_86
action_7 (101) = happyShift action_58
action_7 (102) = happyShift action_87
action_7 (103) = happyShift action_93
action_7 (104) = happyShift action_94
action_7 (107) = happyShift action_28
action_7 (108) = happyShift action_59
action_7 (109) = happyShift action_60
action_7 (110) = happyShift action_61
action_7 (30) = happyGoto action_29
action_7 (31) = happyGoto action_30
action_7 (32) = happyGoto action_31
action_7 (33) = happyGoto action_32
action_7 (40) = happyGoto action_88
action_7 (41) = happyGoto action_89
action_7 (43) = happyGoto action_33
action_7 (44) = happyGoto action_34
action_7 (45) = happyGoto action_35
action_7 (46) = happyGoto action_36
action_7 (47) = happyGoto action_37
action_7 (48) = happyGoto action_38
action_7 (49) = happyGoto action_39
action_7 (50) = happyGoto action_40
action_7 (51) = happyGoto action_41
action_7 (52) = happyGoto action_42
action_7 (53) = happyGoto action_43
action_7 (54) = happyGoto action_44
action_7 (55) = happyGoto action_90
action_7 (56) = happyGoto action_46
action_7 (57) = happyGoto action_47
action_7 (58) = happyGoto action_48
action_7 (59) = happyGoto action_49
action_7 _ = happyFail

action_8 (93) = happyShift action_83
action_8 (94) = happyShift action_84
action_8 (98) = happyShift action_85
action_8 (100) = happyShift action_86
action_8 (102) = happyShift action_87
action_8 (40) = happyGoto action_81
action_8 (42) = happyGoto action_82
action_8 _ = happyFail

action_9 (66) = happyShift action_52
action_9 (96) = happyShift action_57
action_9 (101) = happyShift action_58
action_9 (107) = happyShift action_28
action_9 (108) = happyShift action_59
action_9 (109) = happyShift action_60
action_9 (110) = happyShift action_61
action_9 (30) = happyGoto action_29
action_9 (31) = happyGoto action_30
action_9 (32) = happyGoto action_31
action_9 (33) = happyGoto action_79
action_9 (43) = happyGoto action_80
action_9 _ = happyFail

action_10 (66) = happyShift action_52
action_10 (96) = happyShift action_57
action_10 (101) = happyShift action_58
action_10 (107) = happyShift action_28
action_10 (108) = happyShift action_59
action_10 (109) = happyShift action_60
action_10 (110) = happyShift action_61
action_10 (30) = happyGoto action_29
action_10 (31) = happyGoto action_30
action_10 (32) = happyGoto action_31
action_10 (33) = happyGoto action_77
action_10 (43) = happyGoto action_33
action_10 (44) = happyGoto action_78
action_10 _ = happyFail

action_11 (66) = happyShift action_52
action_11 (68) = happyShift action_53
action_11 (96) = happyShift action_57
action_11 (101) = happyShift action_58
action_11 (107) = happyShift action_28
action_11 (108) = happyShift action_59
action_11 (109) = happyShift action_60
action_11 (110) = happyShift action_61
action_11 (30) = happyGoto action_29
action_11 (31) = happyGoto action_30
action_11 (32) = happyGoto action_31
action_11 (33) = happyGoto action_32
action_11 (43) = happyGoto action_33
action_11 (44) = happyGoto action_34
action_11 (45) = happyGoto action_76
action_11 _ = happyFail

action_12 (62) = happyShift action_51
action_12 (66) = happyShift action_52
action_12 (68) = happyShift action_53
action_12 (70) = happyShift action_54
action_12 (73) = happyShift action_55
action_12 (74) = happyShift action_56
action_12 (96) = happyShift action_57
action_12 (101) = happyShift action_58
action_12 (107) = happyShift action_28
action_12 (108) = happyShift action_59
action_12 (109) = happyShift action_60
action_12 (110) = happyShift action_61
action_12 (30) = happyGoto action_29
action_12 (31) = happyGoto action_30
action_12 (32) = happyGoto action_31
action_12 (33) = happyGoto action_32
action_12 (43) = happyGoto action_33
action_12 (44) = happyGoto action_34
action_12 (45) = happyGoto action_35
action_12 (46) = happyGoto action_75
action_12 _ = happyFail

action_13 (62) = happyShift action_51
action_13 (66) = happyShift action_52
action_13 (68) = happyShift action_53
action_13 (70) = happyShift action_54
action_13 (73) = happyShift action_55
action_13 (74) = happyShift action_56
action_13 (96) = happyShift action_57
action_13 (101) = happyShift action_58
action_13 (107) = happyShift action_28
action_13 (108) = happyShift action_59
action_13 (109) = happyShift action_60
action_13 (110) = happyShift action_61
action_13 (30) = happyGoto action_29
action_13 (31) = happyGoto action_30
action_13 (32) = happyGoto action_31
action_13 (33) = happyGoto action_32
action_13 (43) = happyGoto action_33
action_13 (44) = happyGoto action_34
action_13 (45) = happyGoto action_35
action_13 (46) = happyGoto action_36
action_13 (47) = happyGoto action_74
action_13 _ = happyFail

action_14 (62) = happyShift action_51
action_14 (66) = happyShift action_52
action_14 (68) = happyShift action_53
action_14 (70) = happyShift action_54
action_14 (73) = happyShift action_55
action_14 (74) = happyShift action_56
action_14 (96) = happyShift action_57
action_14 (101) = happyShift action_58
action_14 (107) = happyShift action_28
action_14 (108) = happyShift action_59
action_14 (109) = happyShift action_60
action_14 (110) = happyShift action_61
action_14 (30) = happyGoto action_29
action_14 (31) = happyGoto action_30
action_14 (32) = happyGoto action_31
action_14 (33) = happyGoto action_32
action_14 (43) = happyGoto action_33
action_14 (44) = happyGoto action_34
action_14 (45) = happyGoto action_35
action_14 (46) = happyGoto action_36
action_14 (47) = happyGoto action_37
action_14 (48) = happyGoto action_73
action_14 _ = happyFail

action_15 (62) = happyShift action_51
action_15 (66) = happyShift action_52
action_15 (68) = happyShift action_53
action_15 (70) = happyShift action_54
action_15 (73) = happyShift action_55
action_15 (74) = happyShift action_56
action_15 (96) = happyShift action_57
action_15 (101) = happyShift action_58
action_15 (107) = happyShift action_28
action_15 (108) = happyShift action_59
action_15 (109) = happyShift action_60
action_15 (110) = happyShift action_61
action_15 (30) = happyGoto action_29
action_15 (31) = happyGoto action_30
action_15 (32) = happyGoto action_31
action_15 (33) = happyGoto action_32
action_15 (43) = happyGoto action_33
action_15 (44) = happyGoto action_34
action_15 (45) = happyGoto action_35
action_15 (46) = happyGoto action_36
action_15 (47) = happyGoto action_37
action_15 (48) = happyGoto action_38
action_15 (49) = happyGoto action_72
action_15 _ = happyFail

action_16 (62) = happyShift action_51
action_16 (66) = happyShift action_52
action_16 (68) = happyShift action_53
action_16 (70) = happyShift action_54
action_16 (73) = happyShift action_55
action_16 (74) = happyShift action_56
action_16 (96) = happyShift action_57
action_16 (101) = happyShift action_58
action_16 (107) = happyShift action_28
action_16 (108) = happyShift action_59
action_16 (109) = happyShift action_60
action_16 (110) = happyShift action_61
action_16 (30) = happyGoto action_29
action_16 (31) = happyGoto action_30
action_16 (32) = happyGoto action_31
action_16 (33) = happyGoto action_32
action_16 (43) = happyGoto action_33
action_16 (44) = happyGoto action_34
action_16 (45) = happyGoto action_35
action_16 (46) = happyGoto action_36
action_16 (47) = happyGoto action_37
action_16 (48) = happyGoto action_38
action_16 (49) = happyGoto action_39
action_16 (50) = happyGoto action_71
action_16 _ = happyFail

action_17 (62) = happyShift action_51
action_17 (66) = happyShift action_52
action_17 (68) = happyShift action_53
action_17 (70) = happyShift action_54
action_17 (73) = happyShift action_55
action_17 (74) = happyShift action_56
action_17 (96) = happyShift action_57
action_17 (101) = happyShift action_58
action_17 (107) = happyShift action_28
action_17 (108) = happyShift action_59
action_17 (109) = happyShift action_60
action_17 (110) = happyShift action_61
action_17 (30) = happyGoto action_29
action_17 (31) = happyGoto action_30
action_17 (32) = happyGoto action_31
action_17 (33) = happyGoto action_32
action_17 (43) = happyGoto action_33
action_17 (44) = happyGoto action_34
action_17 (45) = happyGoto action_35
action_17 (46) = happyGoto action_36
action_17 (47) = happyGoto action_37
action_17 (48) = happyGoto action_38
action_17 (49) = happyGoto action_39
action_17 (50) = happyGoto action_40
action_17 (51) = happyGoto action_70
action_17 _ = happyFail

action_18 (62) = happyShift action_51
action_18 (66) = happyShift action_52
action_18 (68) = happyShift action_53
action_18 (70) = happyShift action_54
action_18 (73) = happyShift action_55
action_18 (74) = happyShift action_56
action_18 (96) = happyShift action_57
action_18 (101) = happyShift action_58
action_18 (107) = happyShift action_28
action_18 (108) = happyShift action_59
action_18 (109) = happyShift action_60
action_18 (110) = happyShift action_61
action_18 (30) = happyGoto action_29
action_18 (31) = happyGoto action_30
action_18 (32) = happyGoto action_31
action_18 (33) = happyGoto action_32
action_18 (43) = happyGoto action_33
action_18 (44) = happyGoto action_34
action_18 (45) = happyGoto action_35
action_18 (46) = happyGoto action_36
action_18 (47) = happyGoto action_37
action_18 (48) = happyGoto action_38
action_18 (49) = happyGoto action_39
action_18 (50) = happyGoto action_40
action_18 (51) = happyGoto action_41
action_18 (52) = happyGoto action_69
action_18 (57) = happyGoto action_47
action_18 (58) = happyGoto action_48
action_18 (59) = happyGoto action_49
action_18 _ = happyFail

action_19 (62) = happyShift action_51
action_19 (66) = happyShift action_52
action_19 (68) = happyShift action_53
action_19 (70) = happyShift action_54
action_19 (73) = happyShift action_55
action_19 (74) = happyShift action_56
action_19 (96) = happyShift action_57
action_19 (101) = happyShift action_58
action_19 (107) = happyShift action_28
action_19 (108) = happyShift action_59
action_19 (109) = happyShift action_60
action_19 (110) = happyShift action_61
action_19 (30) = happyGoto action_29
action_19 (31) = happyGoto action_30
action_19 (32) = happyGoto action_31
action_19 (33) = happyGoto action_32
action_19 (43) = happyGoto action_33
action_19 (44) = happyGoto action_34
action_19 (45) = happyGoto action_35
action_19 (46) = happyGoto action_36
action_19 (47) = happyGoto action_37
action_19 (48) = happyGoto action_38
action_19 (49) = happyGoto action_39
action_19 (50) = happyGoto action_40
action_19 (51) = happyGoto action_41
action_19 (52) = happyGoto action_42
action_19 (53) = happyGoto action_68
action_19 (57) = happyGoto action_47
action_19 (58) = happyGoto action_48
action_19 (59) = happyGoto action_49
action_19 _ = happyFail

action_20 (62) = happyShift action_51
action_20 (66) = happyShift action_52
action_20 (68) = happyShift action_53
action_20 (70) = happyShift action_54
action_20 (73) = happyShift action_55
action_20 (74) = happyShift action_56
action_20 (96) = happyShift action_57
action_20 (101) = happyShift action_58
action_20 (107) = happyShift action_28
action_20 (108) = happyShift action_59
action_20 (109) = happyShift action_60
action_20 (110) = happyShift action_61
action_20 (30) = happyGoto action_29
action_20 (31) = happyGoto action_30
action_20 (32) = happyGoto action_31
action_20 (33) = happyGoto action_32
action_20 (43) = happyGoto action_33
action_20 (44) = happyGoto action_34
action_20 (45) = happyGoto action_35
action_20 (46) = happyGoto action_36
action_20 (47) = happyGoto action_37
action_20 (48) = happyGoto action_38
action_20 (49) = happyGoto action_39
action_20 (50) = happyGoto action_40
action_20 (51) = happyGoto action_41
action_20 (52) = happyGoto action_42
action_20 (53) = happyGoto action_43
action_20 (54) = happyGoto action_67
action_20 (57) = happyGoto action_47
action_20 (58) = happyGoto action_48
action_20 (59) = happyGoto action_49
action_20 _ = happyFail

action_21 (62) = happyShift action_51
action_21 (66) = happyShift action_52
action_21 (68) = happyShift action_53
action_21 (70) = happyShift action_54
action_21 (73) = happyShift action_55
action_21 (74) = happyShift action_56
action_21 (96) = happyShift action_57
action_21 (101) = happyShift action_58
action_21 (107) = happyShift action_28
action_21 (108) = happyShift action_59
action_21 (109) = happyShift action_60
action_21 (110) = happyShift action_61
action_21 (30) = happyGoto action_29
action_21 (31) = happyGoto action_30
action_21 (32) = happyGoto action_31
action_21 (33) = happyGoto action_32
action_21 (43) = happyGoto action_33
action_21 (44) = happyGoto action_34
action_21 (45) = happyGoto action_35
action_21 (46) = happyGoto action_36
action_21 (47) = happyGoto action_37
action_21 (48) = happyGoto action_38
action_21 (49) = happyGoto action_39
action_21 (50) = happyGoto action_40
action_21 (51) = happyGoto action_41
action_21 (52) = happyGoto action_42
action_21 (53) = happyGoto action_43
action_21 (54) = happyGoto action_44
action_21 (55) = happyGoto action_66
action_21 (56) = happyGoto action_46
action_21 (57) = happyGoto action_47
action_21 (58) = happyGoto action_48
action_21 (59) = happyGoto action_49
action_21 _ = happyFail

action_22 (62) = happyShift action_51
action_22 (66) = happyShift action_52
action_22 (68) = happyShift action_53
action_22 (70) = happyShift action_54
action_22 (73) = happyShift action_55
action_22 (74) = happyShift action_56
action_22 (96) = happyShift action_57
action_22 (101) = happyShift action_58
action_22 (107) = happyShift action_28
action_22 (108) = happyShift action_59
action_22 (109) = happyShift action_60
action_22 (110) = happyShift action_61
action_22 (30) = happyGoto action_29
action_22 (31) = happyGoto action_30
action_22 (32) = happyGoto action_31
action_22 (33) = happyGoto action_32
action_22 (43) = happyGoto action_33
action_22 (44) = happyGoto action_34
action_22 (45) = happyGoto action_35
action_22 (46) = happyGoto action_36
action_22 (47) = happyGoto action_37
action_22 (48) = happyGoto action_38
action_22 (49) = happyGoto action_39
action_22 (50) = happyGoto action_40
action_22 (51) = happyGoto action_41
action_22 (52) = happyGoto action_42
action_22 (53) = happyGoto action_43
action_22 (54) = happyGoto action_44
action_22 (56) = happyGoto action_65
action_22 (57) = happyGoto action_47
action_22 (58) = happyGoto action_48
action_22 (59) = happyGoto action_49
action_22 _ = happyFail

action_23 (62) = happyShift action_51
action_23 (66) = happyShift action_52
action_23 (68) = happyShift action_53
action_23 (70) = happyShift action_54
action_23 (73) = happyShift action_55
action_23 (74) = happyShift action_56
action_23 (96) = happyShift action_57
action_23 (101) = happyShift action_58
action_23 (107) = happyShift action_28
action_23 (108) = happyShift action_59
action_23 (109) = happyShift action_60
action_23 (110) = happyShift action_61
action_23 (30) = happyGoto action_29
action_23 (31) = happyGoto action_30
action_23 (32) = happyGoto action_31
action_23 (33) = happyGoto action_32
action_23 (43) = happyGoto action_33
action_23 (44) = happyGoto action_34
action_23 (45) = happyGoto action_35
action_23 (46) = happyGoto action_36
action_23 (47) = happyGoto action_37
action_23 (48) = happyGoto action_38
action_23 (49) = happyGoto action_39
action_23 (50) = happyGoto action_40
action_23 (51) = happyGoto action_41
action_23 (57) = happyGoto action_64
action_23 (58) = happyGoto action_48
action_23 (59) = happyGoto action_49
action_23 _ = happyFail

action_24 (62) = happyShift action_51
action_24 (66) = happyShift action_52
action_24 (68) = happyShift action_53
action_24 (70) = happyShift action_54
action_24 (73) = happyShift action_55
action_24 (74) = happyShift action_56
action_24 (96) = happyShift action_57
action_24 (101) = happyShift action_58
action_24 (107) = happyShift action_28
action_24 (108) = happyShift action_59
action_24 (109) = happyShift action_60
action_24 (110) = happyShift action_61
action_24 (30) = happyGoto action_29
action_24 (31) = happyGoto action_30
action_24 (32) = happyGoto action_31
action_24 (33) = happyGoto action_32
action_24 (43) = happyGoto action_33
action_24 (44) = happyGoto action_34
action_24 (45) = happyGoto action_35
action_24 (46) = happyGoto action_36
action_24 (47) = happyGoto action_37
action_24 (48) = happyGoto action_38
action_24 (49) = happyGoto action_39
action_24 (50) = happyGoto action_40
action_24 (51) = happyGoto action_41
action_24 (58) = happyGoto action_63
action_24 (59) = happyGoto action_49
action_24 _ = happyFail

action_25 (62) = happyShift action_51
action_25 (66) = happyShift action_52
action_25 (68) = happyShift action_53
action_25 (70) = happyShift action_54
action_25 (73) = happyShift action_55
action_25 (74) = happyShift action_56
action_25 (96) = happyShift action_57
action_25 (101) = happyShift action_58
action_25 (107) = happyShift action_28
action_25 (108) = happyShift action_59
action_25 (109) = happyShift action_60
action_25 (110) = happyShift action_61
action_25 (30) = happyGoto action_29
action_25 (31) = happyGoto action_30
action_25 (32) = happyGoto action_31
action_25 (33) = happyGoto action_32
action_25 (43) = happyGoto action_33
action_25 (44) = happyGoto action_34
action_25 (45) = happyGoto action_35
action_25 (46) = happyGoto action_36
action_25 (47) = happyGoto action_37
action_25 (48) = happyGoto action_38
action_25 (49) = happyGoto action_39
action_25 (50) = happyGoto action_40
action_25 (51) = happyGoto action_41
action_25 (59) = happyGoto action_62
action_25 _ = happyFail

action_26 (62) = happyShift action_51
action_26 (66) = happyShift action_52
action_26 (68) = happyShift action_53
action_26 (70) = happyShift action_54
action_26 (73) = happyShift action_55
action_26 (74) = happyShift action_56
action_26 (96) = happyShift action_57
action_26 (101) = happyShift action_58
action_26 (107) = happyShift action_28
action_26 (108) = happyShift action_59
action_26 (109) = happyShift action_60
action_26 (110) = happyShift action_61
action_26 (30) = happyGoto action_29
action_26 (31) = happyGoto action_30
action_26 (32) = happyGoto action_31
action_26 (33) = happyGoto action_32
action_26 (43) = happyGoto action_33
action_26 (44) = happyGoto action_34
action_26 (45) = happyGoto action_35
action_26 (46) = happyGoto action_36
action_26 (47) = happyGoto action_37
action_26 (48) = happyGoto action_38
action_26 (49) = happyGoto action_39
action_26 (50) = happyGoto action_40
action_26 (51) = happyGoto action_41
action_26 (52) = happyGoto action_42
action_26 (53) = happyGoto action_43
action_26 (54) = happyGoto action_44
action_26 (55) = happyGoto action_45
action_26 (56) = happyGoto action_46
action_26 (57) = happyGoto action_47
action_26 (58) = happyGoto action_48
action_26 (59) = happyGoto action_49
action_26 (60) = happyGoto action_50
action_26 _ = happyReduce_110

action_27 (107) = happyShift action_28
action_27 _ = happyFail

action_28 _ = happyReduce_27

action_29 _ = happyReduce_56

action_30 _ = happyReduce_57

action_31 _ = happyReduce_58

action_32 (66) = happyShift action_118
action_32 (76) = happyShift action_149
action_32 (77) = happyShift action_150
action_32 (80) = happyShift action_119
action_32 (91) = happyShift action_120
action_32 _ = happyReduce_61

action_33 _ = happyReduce_66

action_34 (70) = happyShift action_147
action_34 (74) = happyShift action_148
action_34 _ = happyReduce_72

action_35 _ = happyReduce_77

action_36 _ = happyReduce_81

action_37 (64) = happyShift action_121
action_37 (68) = happyShift action_122
action_37 (78) = happyShift action_123
action_37 _ = happyReduce_84

action_38 (69) = happyShift action_124
action_38 (73) = happyShift action_125
action_38 _ = happyReduce_87

action_39 (83) = happyShift action_126
action_39 (89) = happyShift action_127
action_39 _ = happyReduce_92

action_40 (82) = happyShift action_128
action_40 (84) = happyShift action_129
action_40 (87) = happyShift action_130
action_40 (88) = happyShift action_131
action_40 _ = happyReduce_95

action_41 (63) = happyShift action_132
action_41 (86) = happyShift action_133
action_41 _ = happyReduce_109

action_42 (65) = happyShift action_134
action_42 _ = happyReduce_99

action_43 (71) = happyShift action_143
action_43 (75) = happyShift action_144
action_43 (85) = happyShift action_145
action_43 (90) = happyShift action_146
action_43 (105) = happyShift action_135
action_43 _ = happyReduce_104

action_44 _ = happyReduce_106

action_45 (72) = happyShift action_142
action_45 _ = happyReduce_111

action_46 _ = happyReduce_105

action_47 _ = happyReduce_97

action_48 _ = happyReduce_107

action_49 _ = happyReduce_108

action_50 (111) = happyAccept
action_50 _ = happyFail

action_51 (66) = happyShift action_52
action_51 (96) = happyShift action_57
action_51 (101) = happyShift action_58
action_51 (107) = happyShift action_28
action_51 (108) = happyShift action_59
action_51 (109) = happyShift action_60
action_51 (110) = happyShift action_61
action_51 (30) = happyGoto action_29
action_51 (31) = happyGoto action_30
action_51 (32) = happyGoto action_31
action_51 (33) = happyGoto action_79
action_51 (43) = happyGoto action_141
action_51 _ = happyFail

action_52 (62) = happyShift action_51
action_52 (66) = happyShift action_52
action_52 (68) = happyShift action_53
action_52 (70) = happyShift action_54
action_52 (73) = happyShift action_55
action_52 (74) = happyShift action_56
action_52 (96) = happyShift action_57
action_52 (101) = happyShift action_58
action_52 (107) = happyShift action_28
action_52 (108) = happyShift action_59
action_52 (109) = happyShift action_60
action_52 (110) = happyShift action_61
action_52 (30) = happyGoto action_29
action_52 (31) = happyGoto action_30
action_52 (32) = happyGoto action_31
action_52 (33) = happyGoto action_32
action_52 (43) = happyGoto action_33
action_52 (44) = happyGoto action_34
action_52 (45) = happyGoto action_35
action_52 (46) = happyGoto action_36
action_52 (47) = happyGoto action_37
action_52 (48) = happyGoto action_38
action_52 (49) = happyGoto action_39
action_52 (50) = happyGoto action_40
action_52 (51) = happyGoto action_41
action_52 (52) = happyGoto action_42
action_52 (53) = happyGoto action_43
action_52 (54) = happyGoto action_44
action_52 (55) = happyGoto action_140
action_52 (56) = happyGoto action_46
action_52 (57) = happyGoto action_47
action_52 (58) = happyGoto action_48
action_52 (59) = happyGoto action_49
action_52 _ = happyFail

action_53 (110) = happyShift action_61
action_53 (33) = happyGoto action_139
action_53 _ = happyFail

action_54 (66) = happyShift action_52
action_54 (68) = happyShift action_53
action_54 (96) = happyShift action_57
action_54 (101) = happyShift action_58
action_54 (107) = happyShift action_28
action_54 (108) = happyShift action_59
action_54 (109) = happyShift action_60
action_54 (110) = happyShift action_61
action_54 (30) = happyGoto action_29
action_54 (31) = happyGoto action_30
action_54 (32) = happyGoto action_31
action_54 (33) = happyGoto action_32
action_54 (43) = happyGoto action_33
action_54 (44) = happyGoto action_34
action_54 (45) = happyGoto action_138
action_54 _ = happyFail

action_55 (66) = happyShift action_52
action_55 (68) = happyShift action_53
action_55 (96) = happyShift action_57
action_55 (101) = happyShift action_58
action_55 (107) = happyShift action_28
action_55 (108) = happyShift action_59
action_55 (109) = happyShift action_60
action_55 (110) = happyShift action_61
action_55 (30) = happyGoto action_29
action_55 (31) = happyGoto action_30
action_55 (32) = happyGoto action_31
action_55 (33) = happyGoto action_32
action_55 (43) = happyGoto action_33
action_55 (44) = happyGoto action_34
action_55 (45) = happyGoto action_137
action_55 _ = happyFail

action_56 (66) = happyShift action_52
action_56 (68) = happyShift action_53
action_56 (96) = happyShift action_57
action_56 (101) = happyShift action_58
action_56 (107) = happyShift action_28
action_56 (108) = happyShift action_59
action_56 (109) = happyShift action_60
action_56 (110) = happyShift action_61
action_56 (30) = happyGoto action_29
action_56 (31) = happyGoto action_30
action_56 (32) = happyGoto action_31
action_56 (33) = happyGoto action_32
action_56 (43) = happyGoto action_33
action_56 (44) = happyGoto action_34
action_56 (45) = happyGoto action_136
action_56 _ = happyFail

action_57 _ = happyReduce_60

action_58 _ = happyReduce_59

action_59 _ = happyReduce_28

action_60 _ = happyReduce_29

action_61 _ = happyReduce_30

action_62 (111) = happyAccept
action_62 _ = happyFail

action_63 (111) = happyAccept
action_63 _ = happyFail

action_64 (111) = happyAccept
action_64 _ = happyFail

action_65 (111) = happyAccept
action_65 _ = happyFail

action_66 (111) = happyAccept
action_66 _ = happyFail

action_67 (111) = happyAccept
action_67 _ = happyFail

action_68 (105) = happyShift action_135
action_68 (111) = happyAccept
action_68 _ = happyFail

action_69 (65) = happyShift action_134
action_69 (111) = happyAccept
action_69 _ = happyFail

action_70 (63) = happyShift action_132
action_70 (86) = happyShift action_133
action_70 (111) = happyAccept
action_70 _ = happyFail

action_71 (82) = happyShift action_128
action_71 (84) = happyShift action_129
action_71 (87) = happyShift action_130
action_71 (88) = happyShift action_131
action_71 (111) = happyAccept
action_71 _ = happyFail

action_72 (83) = happyShift action_126
action_72 (89) = happyShift action_127
action_72 (111) = happyAccept
action_72 _ = happyFail

action_73 (69) = happyShift action_124
action_73 (73) = happyShift action_125
action_73 (111) = happyAccept
action_73 _ = happyFail

action_74 (64) = happyShift action_121
action_74 (68) = happyShift action_122
action_74 (78) = happyShift action_123
action_74 (111) = happyAccept
action_74 _ = happyFail

action_75 (111) = happyAccept
action_75 _ = happyFail

action_76 (111) = happyAccept
action_76 _ = happyFail

action_77 (66) = happyShift action_118
action_77 (80) = happyShift action_119
action_77 (91) = happyShift action_120
action_77 _ = happyReduce_61

action_78 (111) = happyAccept
action_78 _ = happyFail

action_79 _ = happyReduce_61

action_80 (111) = happyAccept
action_80 _ = happyFail

action_81 (110) = happyShift action_61
action_81 (33) = happyGoto action_117
action_81 _ = happyFail

action_82 (111) = happyAccept
action_82 _ = happyFail

action_83 _ = happyReduce_42

action_84 _ = happyReduce_43

action_85 _ = happyReduce_44

action_86 _ = happyReduce_45

action_87 _ = happyReduce_46

action_88 (110) = happyShift action_61
action_88 (33) = happyGoto action_116
action_88 _ = happyFail

action_89 (111) = happyAccept
action_89 _ = happyFail

action_90 (81) = happyShift action_115
action_90 _ = happyFail

action_91 (66) = happyShift action_114
action_91 _ = happyFail

action_92 (62) = happyShift action_51
action_92 (66) = happyShift action_52
action_92 (68) = happyShift action_53
action_92 (70) = happyShift action_54
action_92 (73) = happyShift action_55
action_92 (74) = happyShift action_56
action_92 (96) = happyShift action_57
action_92 (101) = happyShift action_58
action_92 (107) = happyShift action_28
action_92 (108) = happyShift action_59
action_92 (109) = happyShift action_60
action_92 (110) = happyShift action_61
action_92 (30) = happyGoto action_29
action_92 (31) = happyGoto action_30
action_92 (32) = happyGoto action_31
action_92 (33) = happyGoto action_32
action_92 (43) = happyGoto action_33
action_92 (44) = happyGoto action_34
action_92 (45) = happyGoto action_35
action_92 (46) = happyGoto action_36
action_92 (47) = happyGoto action_37
action_92 (48) = happyGoto action_38
action_92 (49) = happyGoto action_39
action_92 (50) = happyGoto action_40
action_92 (51) = happyGoto action_41
action_92 (52) = happyGoto action_42
action_92 (53) = happyGoto action_43
action_92 (54) = happyGoto action_44
action_92 (55) = happyGoto action_113
action_92 (56) = happyGoto action_46
action_92 (57) = happyGoto action_47
action_92 (58) = happyGoto action_48
action_92 (59) = happyGoto action_49
action_92 _ = happyFail

action_93 (66) = happyShift action_112
action_93 _ = happyFail

action_94 (37) = happyGoto action_111
action_94 _ = happyReduce_35

action_95 (111) = happyAccept
action_95 _ = happyFail

action_96 (72) = happyShift action_110
action_96 _ = happyReduce_40

action_97 (111) = happyAccept
action_97 _ = happyFail

action_98 (111) = happyAccept
action_98 _ = happyFail

action_99 (72) = happyShift action_109
action_99 _ = happyReduce_38

action_100 (62) = happyShift action_51
action_100 (66) = happyShift action_52
action_100 (68) = happyShift action_53
action_100 (70) = happyShift action_54
action_100 (73) = happyShift action_55
action_100 (74) = happyShift action_56
action_100 (93) = happyShift action_83
action_100 (94) = happyShift action_84
action_100 (96) = happyShift action_57
action_100 (97) = happyShift action_91
action_100 (98) = happyShift action_85
action_100 (99) = happyShift action_92
action_100 (100) = happyShift action_86
action_100 (101) = happyShift action_58
action_100 (102) = happyShift action_87
action_100 (103) = happyShift action_93
action_100 (104) = happyShift action_94
action_100 (107) = happyShift action_28
action_100 (108) = happyShift action_59
action_100 (109) = happyShift action_60
action_100 (110) = happyShift action_61
action_100 (111) = happyAccept
action_100 (30) = happyGoto action_29
action_100 (31) = happyGoto action_30
action_100 (32) = happyGoto action_31
action_100 (33) = happyGoto action_32
action_100 (40) = happyGoto action_88
action_100 (41) = happyGoto action_108
action_100 (43) = happyGoto action_33
action_100 (44) = happyGoto action_34
action_100 (45) = happyGoto action_35
action_100 (46) = happyGoto action_36
action_100 (47) = happyGoto action_37
action_100 (48) = happyGoto action_38
action_100 (49) = happyGoto action_39
action_100 (50) = happyGoto action_40
action_100 (51) = happyGoto action_41
action_100 (52) = happyGoto action_42
action_100 (53) = happyGoto action_43
action_100 (54) = happyGoto action_44
action_100 (55) = happyGoto action_90
action_100 (56) = happyGoto action_46
action_100 (57) = happyGoto action_47
action_100 (58) = happyGoto action_48
action_100 (59) = happyGoto action_49
action_100 _ = happyFail

action_101 (93) = happyShift action_83
action_101 (94) = happyShift action_84
action_101 (98) = happyShift action_85
action_101 (100) = happyShift action_86
action_101 (102) = happyShift action_87
action_101 (111) = happyAccept
action_101 (35) = happyGoto action_106
action_101 (40) = happyGoto action_103
action_101 _ = happyFail

action_102 (111) = happyAccept
action_102 _ = happyFail

action_103 (110) = happyShift action_61
action_103 (33) = happyGoto action_107
action_103 _ = happyFail

action_104 (111) = happyAccept
action_104 _ = happyFail

action_105 (93) = happyShift action_83
action_105 (94) = happyShift action_84
action_105 (98) = happyShift action_85
action_105 (100) = happyShift action_86
action_105 (102) = happyShift action_87
action_105 (35) = happyGoto action_106
action_105 (40) = happyGoto action_103
action_105 _ = happyReduce_31

action_106 _ = happyReduce_34

action_107 (66) = happyShift action_186
action_107 _ = happyFail

action_108 _ = happyReduce_36

action_109 (93) = happyShift action_83
action_109 (94) = happyShift action_84
action_109 (98) = happyShift action_85
action_109 (100) = happyShift action_86
action_109 (102) = happyShift action_87
action_109 (38) = happyGoto action_185
action_109 (40) = happyGoto action_81
action_109 (42) = happyGoto action_99
action_109 _ = happyReduce_37

action_110 (110) = happyShift action_61
action_110 (33) = happyGoto action_96
action_110 (39) = happyGoto action_184
action_110 _ = happyFail

action_111 (62) = happyShift action_51
action_111 (66) = happyShift action_52
action_111 (68) = happyShift action_53
action_111 (70) = happyShift action_54
action_111 (73) = happyShift action_55
action_111 (74) = happyShift action_56
action_111 (93) = happyShift action_83
action_111 (94) = happyShift action_84
action_111 (96) = happyShift action_57
action_111 (97) = happyShift action_91
action_111 (98) = happyShift action_85
action_111 (99) = happyShift action_92
action_111 (100) = happyShift action_86
action_111 (101) = happyShift action_58
action_111 (102) = happyShift action_87
action_111 (103) = happyShift action_93
action_111 (104) = happyShift action_94
action_111 (106) = happyShift action_183
action_111 (107) = happyShift action_28
action_111 (108) = happyShift action_59
action_111 (109) = happyShift action_60
action_111 (110) = happyShift action_61
action_111 (30) = happyGoto action_29
action_111 (31) = happyGoto action_30
action_111 (32) = happyGoto action_31
action_111 (33) = happyGoto action_32
action_111 (40) = happyGoto action_88
action_111 (41) = happyGoto action_108
action_111 (43) = happyGoto action_33
action_111 (44) = happyGoto action_34
action_111 (45) = happyGoto action_35
action_111 (46) = happyGoto action_36
action_111 (47) = happyGoto action_37
action_111 (48) = happyGoto action_38
action_111 (49) = happyGoto action_39
action_111 (50) = happyGoto action_40
action_111 (51) = happyGoto action_41
action_111 (52) = happyGoto action_42
action_111 (53) = happyGoto action_43
action_111 (54) = happyGoto action_44
action_111 (55) = happyGoto action_90
action_111 (56) = happyGoto action_46
action_111 (57) = happyGoto action_47
action_111 (58) = happyGoto action_48
action_111 (59) = happyGoto action_49
action_111 _ = happyFail

action_112 (62) = happyShift action_51
action_112 (66) = happyShift action_52
action_112 (68) = happyShift action_53
action_112 (70) = happyShift action_54
action_112 (73) = happyShift action_55
action_112 (74) = happyShift action_56
action_112 (96) = happyShift action_57
action_112 (101) = happyShift action_58
action_112 (107) = happyShift action_28
action_112 (108) = happyShift action_59
action_112 (109) = happyShift action_60
action_112 (110) = happyShift action_61
action_112 (30) = happyGoto action_29
action_112 (31) = happyGoto action_30
action_112 (32) = happyGoto action_31
action_112 (33) = happyGoto action_32
action_112 (43) = happyGoto action_33
action_112 (44) = happyGoto action_34
action_112 (45) = happyGoto action_35
action_112 (46) = happyGoto action_36
action_112 (47) = happyGoto action_37
action_112 (48) = happyGoto action_38
action_112 (49) = happyGoto action_39
action_112 (50) = happyGoto action_40
action_112 (51) = happyGoto action_41
action_112 (52) = happyGoto action_42
action_112 (53) = happyGoto action_43
action_112 (54) = happyGoto action_44
action_112 (55) = happyGoto action_182
action_112 (56) = happyGoto action_46
action_112 (57) = happyGoto action_47
action_112 (58) = happyGoto action_48
action_112 (59) = happyGoto action_49
action_112 _ = happyFail

action_113 (81) = happyShift action_181
action_113 _ = happyFail

action_114 (62) = happyShift action_51
action_114 (66) = happyShift action_52
action_114 (68) = happyShift action_53
action_114 (70) = happyShift action_54
action_114 (73) = happyShift action_55
action_114 (74) = happyShift action_56
action_114 (96) = happyShift action_57
action_114 (101) = happyShift action_58
action_114 (107) = happyShift action_28
action_114 (108) = happyShift action_59
action_114 (109) = happyShift action_60
action_114 (110) = happyShift action_61
action_114 (30) = happyGoto action_29
action_114 (31) = happyGoto action_30
action_114 (32) = happyGoto action_31
action_114 (33) = happyGoto action_32
action_114 (43) = happyGoto action_33
action_114 (44) = happyGoto action_34
action_114 (45) = happyGoto action_35
action_114 (46) = happyGoto action_36
action_114 (47) = happyGoto action_37
action_114 (48) = happyGoto action_38
action_114 (49) = happyGoto action_39
action_114 (50) = happyGoto action_40
action_114 (51) = happyGoto action_41
action_114 (52) = happyGoto action_42
action_114 (53) = happyGoto action_43
action_114 (54) = happyGoto action_44
action_114 (55) = happyGoto action_180
action_114 (56) = happyGoto action_46
action_114 (57) = happyGoto action_47
action_114 (58) = happyGoto action_48
action_114 (59) = happyGoto action_49
action_114 _ = happyFail

action_115 _ = happyReduce_47

action_116 (61) = happyShift action_177
action_116 (72) = happyShift action_178
action_116 (85) = happyShift action_179
action_116 _ = happyFail

action_117 _ = happyReduce_55

action_118 (62) = happyShift action_51
action_118 (66) = happyShift action_52
action_118 (68) = happyShift action_53
action_118 (70) = happyShift action_54
action_118 (73) = happyShift action_55
action_118 (74) = happyShift action_56
action_118 (96) = happyShift action_57
action_118 (101) = happyShift action_58
action_118 (107) = happyShift action_28
action_118 (108) = happyShift action_59
action_118 (109) = happyShift action_60
action_118 (110) = happyShift action_61
action_118 (30) = happyGoto action_29
action_118 (31) = happyGoto action_30
action_118 (32) = happyGoto action_31
action_118 (33) = happyGoto action_32
action_118 (43) = happyGoto action_33
action_118 (44) = happyGoto action_34
action_118 (45) = happyGoto action_35
action_118 (46) = happyGoto action_36
action_118 (47) = happyGoto action_37
action_118 (48) = happyGoto action_38
action_118 (49) = happyGoto action_39
action_118 (50) = happyGoto action_40
action_118 (51) = happyGoto action_41
action_118 (52) = happyGoto action_42
action_118 (53) = happyGoto action_43
action_118 (54) = happyGoto action_44
action_118 (55) = happyGoto action_45
action_118 (56) = happyGoto action_46
action_118 (57) = happyGoto action_47
action_118 (58) = happyGoto action_48
action_118 (59) = happyGoto action_49
action_118 (60) = happyGoto action_176
action_118 _ = happyReduce_110

action_119 (110) = happyShift action_61
action_119 (33) = happyGoto action_175
action_119 _ = happyFail

action_120 (110) = happyShift action_61
action_120 (33) = happyGoto action_174
action_120 _ = happyFail

action_121 (62) = happyShift action_51
action_121 (66) = happyShift action_52
action_121 (68) = happyShift action_53
action_121 (70) = happyShift action_54
action_121 (73) = happyShift action_55
action_121 (74) = happyShift action_56
action_121 (96) = happyShift action_57
action_121 (101) = happyShift action_58
action_121 (107) = happyShift action_28
action_121 (108) = happyShift action_59
action_121 (109) = happyShift action_60
action_121 (110) = happyShift action_61
action_121 (30) = happyGoto action_29
action_121 (31) = happyGoto action_30
action_121 (32) = happyGoto action_31
action_121 (33) = happyGoto action_32
action_121 (43) = happyGoto action_33
action_121 (44) = happyGoto action_34
action_121 (45) = happyGoto action_35
action_121 (46) = happyGoto action_173
action_121 _ = happyFail

action_122 (62) = happyShift action_51
action_122 (66) = happyShift action_52
action_122 (68) = happyShift action_53
action_122 (70) = happyShift action_54
action_122 (73) = happyShift action_55
action_122 (74) = happyShift action_56
action_122 (96) = happyShift action_57
action_122 (101) = happyShift action_58
action_122 (107) = happyShift action_28
action_122 (108) = happyShift action_59
action_122 (109) = happyShift action_60
action_122 (110) = happyShift action_61
action_122 (30) = happyGoto action_29
action_122 (31) = happyGoto action_30
action_122 (32) = happyGoto action_31
action_122 (33) = happyGoto action_32
action_122 (43) = happyGoto action_33
action_122 (44) = happyGoto action_34
action_122 (45) = happyGoto action_35
action_122 (46) = happyGoto action_172
action_122 _ = happyFail

action_123 (62) = happyShift action_51
action_123 (66) = happyShift action_52
action_123 (68) = happyShift action_53
action_123 (70) = happyShift action_54
action_123 (73) = happyShift action_55
action_123 (74) = happyShift action_56
action_123 (96) = happyShift action_57
action_123 (101) = happyShift action_58
action_123 (107) = happyShift action_28
action_123 (108) = happyShift action_59
action_123 (109) = happyShift action_60
action_123 (110) = happyShift action_61
action_123 (30) = happyGoto action_29
action_123 (31) = happyGoto action_30
action_123 (32) = happyGoto action_31
action_123 (33) = happyGoto action_32
action_123 (43) = happyGoto action_33
action_123 (44) = happyGoto action_34
action_123 (45) = happyGoto action_35
action_123 (46) = happyGoto action_171
action_123 _ = happyFail

action_124 (62) = happyShift action_51
action_124 (66) = happyShift action_52
action_124 (68) = happyShift action_53
action_124 (70) = happyShift action_54
action_124 (73) = happyShift action_55
action_124 (74) = happyShift action_56
action_124 (96) = happyShift action_57
action_124 (101) = happyShift action_58
action_124 (107) = happyShift action_28
action_124 (108) = happyShift action_59
action_124 (109) = happyShift action_60
action_124 (110) = happyShift action_61
action_124 (30) = happyGoto action_29
action_124 (31) = happyGoto action_30
action_124 (32) = happyGoto action_31
action_124 (33) = happyGoto action_32
action_124 (43) = happyGoto action_33
action_124 (44) = happyGoto action_34
action_124 (45) = happyGoto action_35
action_124 (46) = happyGoto action_36
action_124 (47) = happyGoto action_170
action_124 _ = happyFail

action_125 (62) = happyShift action_51
action_125 (66) = happyShift action_52
action_125 (68) = happyShift action_53
action_125 (70) = happyShift action_54
action_125 (73) = happyShift action_55
action_125 (74) = happyShift action_56
action_125 (96) = happyShift action_57
action_125 (101) = happyShift action_58
action_125 (107) = happyShift action_28
action_125 (108) = happyShift action_59
action_125 (109) = happyShift action_60
action_125 (110) = happyShift action_61
action_125 (30) = happyGoto action_29
action_125 (31) = happyGoto action_30
action_125 (32) = happyGoto action_31
action_125 (33) = happyGoto action_32
action_125 (43) = happyGoto action_33
action_125 (44) = happyGoto action_34
action_125 (45) = happyGoto action_35
action_125 (46) = happyGoto action_36
action_125 (47) = happyGoto action_169
action_125 _ = happyFail

action_126 (62) = happyShift action_51
action_126 (66) = happyShift action_52
action_126 (68) = happyShift action_53
action_126 (70) = happyShift action_54
action_126 (73) = happyShift action_55
action_126 (74) = happyShift action_56
action_126 (96) = happyShift action_57
action_126 (101) = happyShift action_58
action_126 (107) = happyShift action_28
action_126 (108) = happyShift action_59
action_126 (109) = happyShift action_60
action_126 (110) = happyShift action_61
action_126 (30) = happyGoto action_29
action_126 (31) = happyGoto action_30
action_126 (32) = happyGoto action_31
action_126 (33) = happyGoto action_32
action_126 (43) = happyGoto action_33
action_126 (44) = happyGoto action_34
action_126 (45) = happyGoto action_35
action_126 (46) = happyGoto action_36
action_126 (47) = happyGoto action_37
action_126 (48) = happyGoto action_168
action_126 _ = happyFail

action_127 (62) = happyShift action_51
action_127 (66) = happyShift action_52
action_127 (68) = happyShift action_53
action_127 (70) = happyShift action_54
action_127 (73) = happyShift action_55
action_127 (74) = happyShift action_56
action_127 (96) = happyShift action_57
action_127 (101) = happyShift action_58
action_127 (107) = happyShift action_28
action_127 (108) = happyShift action_59
action_127 (109) = happyShift action_60
action_127 (110) = happyShift action_61
action_127 (30) = happyGoto action_29
action_127 (31) = happyGoto action_30
action_127 (32) = happyGoto action_31
action_127 (33) = happyGoto action_32
action_127 (43) = happyGoto action_33
action_127 (44) = happyGoto action_34
action_127 (45) = happyGoto action_35
action_127 (46) = happyGoto action_36
action_127 (47) = happyGoto action_37
action_127 (48) = happyGoto action_167
action_127 _ = happyFail

action_128 (62) = happyShift action_51
action_128 (66) = happyShift action_52
action_128 (68) = happyShift action_53
action_128 (70) = happyShift action_54
action_128 (73) = happyShift action_55
action_128 (74) = happyShift action_56
action_128 (96) = happyShift action_57
action_128 (101) = happyShift action_58
action_128 (107) = happyShift action_28
action_128 (108) = happyShift action_59
action_128 (109) = happyShift action_60
action_128 (110) = happyShift action_61
action_128 (30) = happyGoto action_29
action_128 (31) = happyGoto action_30
action_128 (32) = happyGoto action_31
action_128 (33) = happyGoto action_32
action_128 (43) = happyGoto action_33
action_128 (44) = happyGoto action_34
action_128 (45) = happyGoto action_35
action_128 (46) = happyGoto action_36
action_128 (47) = happyGoto action_37
action_128 (48) = happyGoto action_38
action_128 (49) = happyGoto action_166
action_128 _ = happyFail

action_129 (62) = happyShift action_51
action_129 (66) = happyShift action_52
action_129 (68) = happyShift action_53
action_129 (70) = happyShift action_54
action_129 (73) = happyShift action_55
action_129 (74) = happyShift action_56
action_129 (96) = happyShift action_57
action_129 (101) = happyShift action_58
action_129 (107) = happyShift action_28
action_129 (108) = happyShift action_59
action_129 (109) = happyShift action_60
action_129 (110) = happyShift action_61
action_129 (30) = happyGoto action_29
action_129 (31) = happyGoto action_30
action_129 (32) = happyGoto action_31
action_129 (33) = happyGoto action_32
action_129 (43) = happyGoto action_33
action_129 (44) = happyGoto action_34
action_129 (45) = happyGoto action_35
action_129 (46) = happyGoto action_36
action_129 (47) = happyGoto action_37
action_129 (48) = happyGoto action_38
action_129 (49) = happyGoto action_165
action_129 _ = happyFail

action_130 (62) = happyShift action_51
action_130 (66) = happyShift action_52
action_130 (68) = happyShift action_53
action_130 (70) = happyShift action_54
action_130 (73) = happyShift action_55
action_130 (74) = happyShift action_56
action_130 (96) = happyShift action_57
action_130 (101) = happyShift action_58
action_130 (107) = happyShift action_28
action_130 (108) = happyShift action_59
action_130 (109) = happyShift action_60
action_130 (110) = happyShift action_61
action_130 (30) = happyGoto action_29
action_130 (31) = happyGoto action_30
action_130 (32) = happyGoto action_31
action_130 (33) = happyGoto action_32
action_130 (43) = happyGoto action_33
action_130 (44) = happyGoto action_34
action_130 (45) = happyGoto action_35
action_130 (46) = happyGoto action_36
action_130 (47) = happyGoto action_37
action_130 (48) = happyGoto action_38
action_130 (49) = happyGoto action_164
action_130 _ = happyFail

action_131 (62) = happyShift action_51
action_131 (66) = happyShift action_52
action_131 (68) = happyShift action_53
action_131 (70) = happyShift action_54
action_131 (73) = happyShift action_55
action_131 (74) = happyShift action_56
action_131 (96) = happyShift action_57
action_131 (101) = happyShift action_58
action_131 (107) = happyShift action_28
action_131 (108) = happyShift action_59
action_131 (109) = happyShift action_60
action_131 (110) = happyShift action_61
action_131 (30) = happyGoto action_29
action_131 (31) = happyGoto action_30
action_131 (32) = happyGoto action_31
action_131 (33) = happyGoto action_32
action_131 (43) = happyGoto action_33
action_131 (44) = happyGoto action_34
action_131 (45) = happyGoto action_35
action_131 (46) = happyGoto action_36
action_131 (47) = happyGoto action_37
action_131 (48) = happyGoto action_38
action_131 (49) = happyGoto action_163
action_131 _ = happyFail

action_132 (62) = happyShift action_51
action_132 (66) = happyShift action_52
action_132 (68) = happyShift action_53
action_132 (70) = happyShift action_54
action_132 (73) = happyShift action_55
action_132 (74) = happyShift action_56
action_132 (96) = happyShift action_57
action_132 (101) = happyShift action_58
action_132 (107) = happyShift action_28
action_132 (108) = happyShift action_59
action_132 (109) = happyShift action_60
action_132 (110) = happyShift action_61
action_132 (30) = happyGoto action_29
action_132 (31) = happyGoto action_30
action_132 (32) = happyGoto action_31
action_132 (33) = happyGoto action_32
action_132 (43) = happyGoto action_33
action_132 (44) = happyGoto action_34
action_132 (45) = happyGoto action_35
action_132 (46) = happyGoto action_36
action_132 (47) = happyGoto action_37
action_132 (48) = happyGoto action_38
action_132 (49) = happyGoto action_39
action_132 (50) = happyGoto action_162
action_132 _ = happyFail

action_133 (62) = happyShift action_51
action_133 (66) = happyShift action_52
action_133 (68) = happyShift action_53
action_133 (70) = happyShift action_54
action_133 (73) = happyShift action_55
action_133 (74) = happyShift action_56
action_133 (96) = happyShift action_57
action_133 (101) = happyShift action_58
action_133 (107) = happyShift action_28
action_133 (108) = happyShift action_59
action_133 (109) = happyShift action_60
action_133 (110) = happyShift action_61
action_133 (30) = happyGoto action_29
action_133 (31) = happyGoto action_30
action_133 (32) = happyGoto action_31
action_133 (33) = happyGoto action_32
action_133 (43) = happyGoto action_33
action_133 (44) = happyGoto action_34
action_133 (45) = happyGoto action_35
action_133 (46) = happyGoto action_36
action_133 (47) = happyGoto action_37
action_133 (48) = happyGoto action_38
action_133 (49) = happyGoto action_39
action_133 (50) = happyGoto action_161
action_133 _ = happyFail

action_134 (62) = happyShift action_51
action_134 (66) = happyShift action_52
action_134 (68) = happyShift action_53
action_134 (70) = happyShift action_54
action_134 (73) = happyShift action_55
action_134 (74) = happyShift action_56
action_134 (96) = happyShift action_57
action_134 (101) = happyShift action_58
action_134 (107) = happyShift action_28
action_134 (108) = happyShift action_59
action_134 (109) = happyShift action_60
action_134 (110) = happyShift action_61
action_134 (30) = happyGoto action_29
action_134 (31) = happyGoto action_30
action_134 (32) = happyGoto action_31
action_134 (33) = happyGoto action_32
action_134 (43) = happyGoto action_33
action_134 (44) = happyGoto action_34
action_134 (45) = happyGoto action_35
action_134 (46) = happyGoto action_36
action_134 (47) = happyGoto action_37
action_134 (48) = happyGoto action_38
action_134 (49) = happyGoto action_39
action_134 (50) = happyGoto action_40
action_134 (51) = happyGoto action_41
action_134 (57) = happyGoto action_160
action_134 (58) = happyGoto action_48
action_134 (59) = happyGoto action_49
action_134 _ = happyFail

action_135 (62) = happyShift action_51
action_135 (66) = happyShift action_52
action_135 (68) = happyShift action_53
action_135 (70) = happyShift action_54
action_135 (73) = happyShift action_55
action_135 (74) = happyShift action_56
action_135 (96) = happyShift action_57
action_135 (101) = happyShift action_58
action_135 (107) = happyShift action_28
action_135 (108) = happyShift action_59
action_135 (109) = happyShift action_60
action_135 (110) = happyShift action_61
action_135 (30) = happyGoto action_29
action_135 (31) = happyGoto action_30
action_135 (32) = happyGoto action_31
action_135 (33) = happyGoto action_32
action_135 (43) = happyGoto action_33
action_135 (44) = happyGoto action_34
action_135 (45) = happyGoto action_35
action_135 (46) = happyGoto action_36
action_135 (47) = happyGoto action_37
action_135 (48) = happyGoto action_38
action_135 (49) = happyGoto action_39
action_135 (50) = happyGoto action_40
action_135 (51) = happyGoto action_41
action_135 (52) = happyGoto action_159
action_135 (57) = happyGoto action_47
action_135 (58) = happyGoto action_48
action_135 (59) = happyGoto action_49
action_135 _ = happyFail

action_136 _ = happyReduce_74

action_137 _ = happyReduce_76

action_138 _ = happyReduce_73

action_139 _ = happyReduce_69

action_140 (67) = happyShift action_158
action_140 _ = happyFail

action_141 _ = happyReduce_75

action_142 (62) = happyShift action_51
action_142 (66) = happyShift action_52
action_142 (68) = happyShift action_53
action_142 (70) = happyShift action_54
action_142 (73) = happyShift action_55
action_142 (74) = happyShift action_56
action_142 (96) = happyShift action_57
action_142 (101) = happyShift action_58
action_142 (107) = happyShift action_28
action_142 (108) = happyShift action_59
action_142 (109) = happyShift action_60
action_142 (110) = happyShift action_61
action_142 (30) = happyGoto action_29
action_142 (31) = happyGoto action_30
action_142 (32) = happyGoto action_31
action_142 (33) = happyGoto action_32
action_142 (43) = happyGoto action_33
action_142 (44) = happyGoto action_34
action_142 (45) = happyGoto action_35
action_142 (46) = happyGoto action_36
action_142 (47) = happyGoto action_37
action_142 (48) = happyGoto action_38
action_142 (49) = happyGoto action_39
action_142 (50) = happyGoto action_40
action_142 (51) = happyGoto action_41
action_142 (52) = happyGoto action_42
action_142 (53) = happyGoto action_43
action_142 (54) = happyGoto action_44
action_142 (55) = happyGoto action_45
action_142 (56) = happyGoto action_46
action_142 (57) = happyGoto action_47
action_142 (58) = happyGoto action_48
action_142 (59) = happyGoto action_49
action_142 (60) = happyGoto action_157
action_142 _ = happyReduce_110

action_143 (62) = happyShift action_51
action_143 (66) = happyShift action_52
action_143 (68) = happyShift action_53
action_143 (70) = happyShift action_54
action_143 (73) = happyShift action_55
action_143 (74) = happyShift action_56
action_143 (96) = happyShift action_57
action_143 (101) = happyShift action_58
action_143 (107) = happyShift action_28
action_143 (108) = happyShift action_59
action_143 (109) = happyShift action_60
action_143 (110) = happyShift action_61
action_143 (30) = happyGoto action_29
action_143 (31) = happyGoto action_30
action_143 (32) = happyGoto action_31
action_143 (33) = happyGoto action_32
action_143 (43) = happyGoto action_33
action_143 (44) = happyGoto action_34
action_143 (45) = happyGoto action_35
action_143 (46) = happyGoto action_36
action_143 (47) = happyGoto action_37
action_143 (48) = happyGoto action_38
action_143 (49) = happyGoto action_39
action_143 (50) = happyGoto action_40
action_143 (51) = happyGoto action_41
action_143 (52) = happyGoto action_42
action_143 (53) = happyGoto action_43
action_143 (54) = happyGoto action_156
action_143 (57) = happyGoto action_47
action_143 (58) = happyGoto action_48
action_143 (59) = happyGoto action_49
action_143 _ = happyFail

action_144 (62) = happyShift action_51
action_144 (66) = happyShift action_52
action_144 (68) = happyShift action_53
action_144 (70) = happyShift action_54
action_144 (73) = happyShift action_55
action_144 (74) = happyShift action_56
action_144 (96) = happyShift action_57
action_144 (101) = happyShift action_58
action_144 (107) = happyShift action_28
action_144 (108) = happyShift action_59
action_144 (109) = happyShift action_60
action_144 (110) = happyShift action_61
action_144 (30) = happyGoto action_29
action_144 (31) = happyGoto action_30
action_144 (32) = happyGoto action_31
action_144 (33) = happyGoto action_32
action_144 (43) = happyGoto action_33
action_144 (44) = happyGoto action_34
action_144 (45) = happyGoto action_35
action_144 (46) = happyGoto action_36
action_144 (47) = happyGoto action_37
action_144 (48) = happyGoto action_38
action_144 (49) = happyGoto action_39
action_144 (50) = happyGoto action_40
action_144 (51) = happyGoto action_41
action_144 (52) = happyGoto action_42
action_144 (53) = happyGoto action_43
action_144 (54) = happyGoto action_155
action_144 (57) = happyGoto action_47
action_144 (58) = happyGoto action_48
action_144 (59) = happyGoto action_49
action_144 _ = happyFail

action_145 (62) = happyShift action_51
action_145 (66) = happyShift action_52
action_145 (68) = happyShift action_53
action_145 (70) = happyShift action_54
action_145 (73) = happyShift action_55
action_145 (74) = happyShift action_56
action_145 (96) = happyShift action_57
action_145 (101) = happyShift action_58
action_145 (107) = happyShift action_28
action_145 (108) = happyShift action_59
action_145 (109) = happyShift action_60
action_145 (110) = happyShift action_61
action_145 (30) = happyGoto action_29
action_145 (31) = happyGoto action_30
action_145 (32) = happyGoto action_31
action_145 (33) = happyGoto action_32
action_145 (43) = happyGoto action_33
action_145 (44) = happyGoto action_34
action_145 (45) = happyGoto action_35
action_145 (46) = happyGoto action_36
action_145 (47) = happyGoto action_37
action_145 (48) = happyGoto action_38
action_145 (49) = happyGoto action_39
action_145 (50) = happyGoto action_40
action_145 (51) = happyGoto action_41
action_145 (52) = happyGoto action_42
action_145 (53) = happyGoto action_43
action_145 (54) = happyGoto action_154
action_145 (57) = happyGoto action_47
action_145 (58) = happyGoto action_48
action_145 (59) = happyGoto action_49
action_145 _ = happyFail

action_146 (62) = happyShift action_51
action_146 (66) = happyShift action_52
action_146 (68) = happyShift action_53
action_146 (70) = happyShift action_54
action_146 (73) = happyShift action_55
action_146 (74) = happyShift action_56
action_146 (93) = happyShift action_83
action_146 (94) = happyShift action_84
action_146 (96) = happyShift action_57
action_146 (97) = happyShift action_91
action_146 (98) = happyShift action_85
action_146 (99) = happyShift action_92
action_146 (100) = happyShift action_86
action_146 (101) = happyShift action_58
action_146 (102) = happyShift action_87
action_146 (103) = happyShift action_93
action_146 (104) = happyShift action_94
action_146 (107) = happyShift action_28
action_146 (108) = happyShift action_59
action_146 (109) = happyShift action_60
action_146 (110) = happyShift action_61
action_146 (30) = happyGoto action_29
action_146 (31) = happyGoto action_30
action_146 (32) = happyGoto action_31
action_146 (33) = happyGoto action_32
action_146 (40) = happyGoto action_88
action_146 (41) = happyGoto action_153
action_146 (43) = happyGoto action_33
action_146 (44) = happyGoto action_34
action_146 (45) = happyGoto action_35
action_146 (46) = happyGoto action_36
action_146 (47) = happyGoto action_37
action_146 (48) = happyGoto action_38
action_146 (49) = happyGoto action_39
action_146 (50) = happyGoto action_40
action_146 (51) = happyGoto action_41
action_146 (52) = happyGoto action_42
action_146 (53) = happyGoto action_43
action_146 (54) = happyGoto action_44
action_146 (55) = happyGoto action_90
action_146 (56) = happyGoto action_46
action_146 (57) = happyGoto action_47
action_146 (58) = happyGoto action_48
action_146 (59) = happyGoto action_49
action_146 _ = happyFail

action_147 _ = happyReduce_67

action_148 _ = happyReduce_68

action_149 (110) = happyShift action_61
action_149 (33) = happyGoto action_152
action_149 _ = happyFail

action_150 (110) = happyShift action_61
action_150 (33) = happyGoto action_151
action_150 _ = happyFail

action_151 _ = happyReduce_70

action_152 _ = happyReduce_71

action_153 (79) = happyShift action_194
action_153 _ = happyFail

action_154 _ = happyReduce_100

action_155 _ = happyReduce_102

action_156 _ = happyReduce_101

action_157 _ = happyReduce_112

action_158 _ = happyReduce_62

action_159 (65) = happyShift action_134
action_159 _ = happyReduce_98

action_160 _ = happyReduce_96

action_161 (82) = happyShift action_128
action_161 (84) = happyShift action_129
action_161 (87) = happyShift action_130
action_161 (88) = happyShift action_131
action_161 _ = happyReduce_93

action_162 (82) = happyShift action_128
action_162 (84) = happyShift action_129
action_162 (87) = happyShift action_130
action_162 (88) = happyShift action_131
action_162 _ = happyReduce_94

action_163 (83) = happyShift action_126
action_163 (89) = happyShift action_127
action_163 _ = happyReduce_91

action_164 (83) = happyShift action_126
action_164 (89) = happyShift action_127
action_164 _ = happyReduce_89

action_165 (83) = happyShift action_126
action_165 (89) = happyShift action_127
action_165 _ = happyReduce_90

action_166 (83) = happyShift action_126
action_166 (89) = happyShift action_127
action_166 _ = happyReduce_88

action_167 (69) = happyShift action_124
action_167 (73) = happyShift action_125
action_167 _ = happyReduce_86

action_168 (69) = happyShift action_124
action_168 (73) = happyShift action_125
action_168 _ = happyReduce_85

action_169 (64) = happyShift action_121
action_169 (68) = happyShift action_122
action_169 (78) = happyShift action_123
action_169 _ = happyReduce_83

action_170 (64) = happyShift action_121
action_170 (68) = happyShift action_122
action_170 (78) = happyShift action_123
action_170 _ = happyReduce_82

action_171 _ = happyReduce_79

action_172 _ = happyReduce_78

action_173 _ = happyReduce_80

action_174 (92) = happyShift action_193
action_174 _ = happyFail

action_175 _ = happyReduce_64

action_176 (67) = happyShift action_192
action_176 _ = happyFail

action_177 _ = happyReduce_48

action_178 (110) = happyShift action_61
action_178 (33) = happyGoto action_96
action_178 (39) = happyGoto action_191
action_178 _ = happyFail

action_179 (62) = happyShift action_51
action_179 (66) = happyShift action_52
action_179 (68) = happyShift action_53
action_179 (70) = happyShift action_54
action_179 (73) = happyShift action_55
action_179 (74) = happyShift action_56
action_179 (96) = happyShift action_57
action_179 (101) = happyShift action_58
action_179 (107) = happyShift action_28
action_179 (108) = happyShift action_59
action_179 (109) = happyShift action_60
action_179 (110) = happyShift action_61
action_179 (30) = happyGoto action_29
action_179 (31) = happyGoto action_30
action_179 (32) = happyGoto action_31
action_179 (33) = happyGoto action_32
action_179 (43) = happyGoto action_33
action_179 (44) = happyGoto action_34
action_179 (45) = happyGoto action_35
action_179 (46) = happyGoto action_36
action_179 (47) = happyGoto action_37
action_179 (48) = happyGoto action_38
action_179 (49) = happyGoto action_39
action_179 (50) = happyGoto action_40
action_179 (51) = happyGoto action_41
action_179 (52) = happyGoto action_42
action_179 (53) = happyGoto action_43
action_179 (54) = happyGoto action_44
action_179 (55) = happyGoto action_190
action_179 (56) = happyGoto action_46
action_179 (57) = happyGoto action_47
action_179 (58) = happyGoto action_48
action_179 (59) = happyGoto action_49
action_179 _ = happyFail

action_180 (67) = happyShift action_189
action_180 _ = happyFail

action_181 _ = happyReduce_51

action_182 (67) = happyShift action_188
action_182 _ = happyFail

action_183 _ = happyReduce_53

action_184 _ = happyReduce_41

action_185 _ = happyReduce_39

action_186 (93) = happyShift action_83
action_186 (94) = happyShift action_84
action_186 (98) = happyShift action_85
action_186 (100) = happyShift action_86
action_186 (102) = happyShift action_87
action_186 (38) = happyGoto action_187
action_186 (40) = happyGoto action_81
action_186 (42) = happyGoto action_99
action_186 _ = happyReduce_37

action_187 (67) = happyShift action_200
action_187 _ = happyFail

action_188 (62) = happyShift action_51
action_188 (66) = happyShift action_52
action_188 (68) = happyShift action_53
action_188 (70) = happyShift action_54
action_188 (73) = happyShift action_55
action_188 (74) = happyShift action_56
action_188 (93) = happyShift action_83
action_188 (94) = happyShift action_84
action_188 (96) = happyShift action_57
action_188 (97) = happyShift action_91
action_188 (98) = happyShift action_85
action_188 (99) = happyShift action_92
action_188 (100) = happyShift action_86
action_188 (101) = happyShift action_58
action_188 (102) = happyShift action_87
action_188 (103) = happyShift action_93
action_188 (104) = happyShift action_94
action_188 (107) = happyShift action_28
action_188 (108) = happyShift action_59
action_188 (109) = happyShift action_60
action_188 (110) = happyShift action_61
action_188 (30) = happyGoto action_29
action_188 (31) = happyGoto action_30
action_188 (32) = happyGoto action_31
action_188 (33) = happyGoto action_32
action_188 (40) = happyGoto action_88
action_188 (41) = happyGoto action_199
action_188 (43) = happyGoto action_33
action_188 (44) = happyGoto action_34
action_188 (45) = happyGoto action_35
action_188 (46) = happyGoto action_36
action_188 (47) = happyGoto action_37
action_188 (48) = happyGoto action_38
action_188 (49) = happyGoto action_39
action_188 (50) = happyGoto action_40
action_188 (51) = happyGoto action_41
action_188 (52) = happyGoto action_42
action_188 (53) = happyGoto action_43
action_188 (54) = happyGoto action_44
action_188 (55) = happyGoto action_90
action_188 (56) = happyGoto action_46
action_188 (57) = happyGoto action_47
action_188 (58) = happyGoto action_48
action_188 (59) = happyGoto action_49
action_188 _ = happyFail

action_189 (62) = happyShift action_51
action_189 (66) = happyShift action_52
action_189 (68) = happyShift action_53
action_189 (70) = happyShift action_54
action_189 (73) = happyShift action_55
action_189 (74) = happyShift action_56
action_189 (93) = happyShift action_83
action_189 (94) = happyShift action_84
action_189 (96) = happyShift action_57
action_189 (97) = happyShift action_91
action_189 (98) = happyShift action_85
action_189 (99) = happyShift action_92
action_189 (100) = happyShift action_86
action_189 (101) = happyShift action_58
action_189 (102) = happyShift action_87
action_189 (103) = happyShift action_93
action_189 (104) = happyShift action_94
action_189 (107) = happyShift action_28
action_189 (108) = happyShift action_59
action_189 (109) = happyShift action_60
action_189 (110) = happyShift action_61
action_189 (30) = happyGoto action_29
action_189 (31) = happyGoto action_30
action_189 (32) = happyGoto action_31
action_189 (33) = happyGoto action_32
action_189 (40) = happyGoto action_88
action_189 (41) = happyGoto action_198
action_189 (43) = happyGoto action_33
action_189 (44) = happyGoto action_34
action_189 (45) = happyGoto action_35
action_189 (46) = happyGoto action_36
action_189 (47) = happyGoto action_37
action_189 (48) = happyGoto action_38
action_189 (49) = happyGoto action_39
action_189 (50) = happyGoto action_40
action_189 (51) = happyGoto action_41
action_189 (52) = happyGoto action_42
action_189 (53) = happyGoto action_43
action_189 (54) = happyGoto action_44
action_189 (55) = happyGoto action_90
action_189 (56) = happyGoto action_46
action_189 (57) = happyGoto action_47
action_189 (58) = happyGoto action_48
action_189 (59) = happyGoto action_49
action_189 _ = happyFail

action_190 (81) = happyShift action_197
action_190 _ = happyFail

action_191 (81) = happyShift action_196
action_191 _ = happyFail

action_192 _ = happyReduce_63

action_193 _ = happyReduce_65

action_194 (62) = happyShift action_51
action_194 (66) = happyShift action_52
action_194 (68) = happyShift action_53
action_194 (70) = happyShift action_54
action_194 (73) = happyShift action_55
action_194 (74) = happyShift action_56
action_194 (93) = happyShift action_83
action_194 (94) = happyShift action_84
action_194 (96) = happyShift action_57
action_194 (97) = happyShift action_91
action_194 (98) = happyShift action_85
action_194 (99) = happyShift action_92
action_194 (100) = happyShift action_86
action_194 (101) = happyShift action_58
action_194 (102) = happyShift action_87
action_194 (103) = happyShift action_93
action_194 (104) = happyShift action_94
action_194 (107) = happyShift action_28
action_194 (108) = happyShift action_59
action_194 (109) = happyShift action_60
action_194 (110) = happyShift action_61
action_194 (30) = happyGoto action_29
action_194 (31) = happyGoto action_30
action_194 (32) = happyGoto action_31
action_194 (33) = happyGoto action_32
action_194 (40) = happyGoto action_88
action_194 (41) = happyGoto action_195
action_194 (43) = happyGoto action_33
action_194 (44) = happyGoto action_34
action_194 (45) = happyGoto action_35
action_194 (46) = happyGoto action_36
action_194 (47) = happyGoto action_37
action_194 (48) = happyGoto action_38
action_194 (49) = happyGoto action_39
action_194 (50) = happyGoto action_40
action_194 (51) = happyGoto action_41
action_194 (52) = happyGoto action_42
action_194 (53) = happyGoto action_43
action_194 (54) = happyGoto action_44
action_194 (55) = happyGoto action_90
action_194 (56) = happyGoto action_46
action_194 (57) = happyGoto action_47
action_194 (58) = happyGoto action_48
action_194 (59) = happyGoto action_49
action_194 _ = happyFail

action_195 _ = happyReduce_103

action_196 _ = happyReduce_49

action_197 _ = happyReduce_50

action_198 (95) = happyShift action_202
action_198 _ = happyFail

action_199 _ = happyReduce_52

action_200 (104) = happyShift action_201
action_200 _ = happyFail

action_201 (37) = happyGoto action_204
action_201 _ = happyReduce_35

action_202 (62) = happyShift action_51
action_202 (66) = happyShift action_52
action_202 (68) = happyShift action_53
action_202 (70) = happyShift action_54
action_202 (73) = happyShift action_55
action_202 (74) = happyShift action_56
action_202 (93) = happyShift action_83
action_202 (94) = happyShift action_84
action_202 (96) = happyShift action_57
action_202 (97) = happyShift action_91
action_202 (98) = happyShift action_85
action_202 (99) = happyShift action_92
action_202 (100) = happyShift action_86
action_202 (101) = happyShift action_58
action_202 (102) = happyShift action_87
action_202 (103) = happyShift action_93
action_202 (104) = happyShift action_94
action_202 (107) = happyShift action_28
action_202 (108) = happyShift action_59
action_202 (109) = happyShift action_60
action_202 (110) = happyShift action_61
action_202 (30) = happyGoto action_29
action_202 (31) = happyGoto action_30
action_202 (32) = happyGoto action_31
action_202 (33) = happyGoto action_32
action_202 (40) = happyGoto action_88
action_202 (41) = happyGoto action_203
action_202 (43) = happyGoto action_33
action_202 (44) = happyGoto action_34
action_202 (45) = happyGoto action_35
action_202 (46) = happyGoto action_36
action_202 (47) = happyGoto action_37
action_202 (48) = happyGoto action_38
action_202 (49) = happyGoto action_39
action_202 (50) = happyGoto action_40
action_202 (51) = happyGoto action_41
action_202 (52) = happyGoto action_42
action_202 (53) = happyGoto action_43
action_202 (54) = happyGoto action_44
action_202 (55) = happyGoto action_90
action_202 (56) = happyGoto action_46
action_202 (57) = happyGoto action_47
action_202 (58) = happyGoto action_48
action_202 (59) = happyGoto action_49
action_202 _ = happyFail

action_203 _ = happyReduce_54

action_204 (62) = happyShift action_51
action_204 (66) = happyShift action_52
action_204 (68) = happyShift action_53
action_204 (70) = happyShift action_54
action_204 (73) = happyShift action_55
action_204 (74) = happyShift action_56
action_204 (93) = happyShift action_83
action_204 (94) = happyShift action_84
action_204 (96) = happyShift action_57
action_204 (97) = happyShift action_91
action_204 (98) = happyShift action_85
action_204 (99) = happyShift action_92
action_204 (100) = happyShift action_86
action_204 (101) = happyShift action_58
action_204 (102) = happyShift action_87
action_204 (103) = happyShift action_93
action_204 (104) = happyShift action_94
action_204 (106) = happyShift action_205
action_204 (107) = happyShift action_28
action_204 (108) = happyShift action_59
action_204 (109) = happyShift action_60
action_204 (110) = happyShift action_61
action_204 (30) = happyGoto action_29
action_204 (31) = happyGoto action_30
action_204 (32) = happyGoto action_31
action_204 (33) = happyGoto action_32
action_204 (40) = happyGoto action_88
action_204 (41) = happyGoto action_108
action_204 (43) = happyGoto action_33
action_204 (44) = happyGoto action_34
action_204 (45) = happyGoto action_35
action_204 (46) = happyGoto action_36
action_204 (47) = happyGoto action_37
action_204 (48) = happyGoto action_38
action_204 (49) = happyGoto action_39
action_204 (50) = happyGoto action_40
action_204 (51) = happyGoto action_41
action_204 (52) = happyGoto action_42
action_204 (53) = happyGoto action_43
action_204 (54) = happyGoto action_44
action_204 (55) = happyGoto action_90
action_204 (56) = happyGoto action_46
action_204 (57) = happyGoto action_47
action_204 (58) = happyGoto action_48
action_204 (59) = happyGoto action_49
action_204 _ = happyFail

action_205 _ = happyReduce_32

happyReduce_27 = happySpecReduce_1  30 happyReduction_27
happyReduction_27 (HappyTerminal (PT _ (TI happy_var_1)))
	 =  HappyAbsSyn30
		 ((read ( happy_var_1)) :: Integer
	)
happyReduction_27 _  = notHappyAtAll 

happyReduce_28 = happySpecReduce_1  31 happyReduction_28
happyReduction_28 (HappyTerminal (PT _ (TD happy_var_1)))
	 =  HappyAbsSyn31
		 ((read ( happy_var_1)) :: Double
	)
happyReduction_28 _  = notHappyAtAll 

happyReduce_29 = happySpecReduce_1  32 happyReduction_29
happyReduction_29 (HappyTerminal (PT _ (TL happy_var_1)))
	 =  HappyAbsSyn32
		 (happy_var_1
	)
happyReduction_29 _  = notHappyAtAll 

happyReduce_30 = happySpecReduce_1  33 happyReduction_30
happyReduction_30 (HappyTerminal (PT _ (T_Id happy_var_1)))
	 =  HappyAbsSyn33
		 (Id (happy_var_1)
	)
happyReduction_30 _  = notHappyAtAll 

happyReduce_31 = happySpecReduce_1  34 happyReduction_31
happyReduction_31 (HappyAbsSyn36  happy_var_1)
	 =  HappyAbsSyn34
		 (AbsCPP.PDefs (reverse happy_var_1)
	)
happyReduction_31 _  = notHappyAtAll 

happyReduce_32 = happyReduce 8 35 happyReduction_32
happyReduction_32 (_ `HappyStk`
	(HappyAbsSyn37  happy_var_7) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn38  happy_var_4) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn33  happy_var_2) `HappyStk`
	(HappyAbsSyn40  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn35
		 (AbsCPP.DFunc happy_var_1 happy_var_2 happy_var_4 (reverse happy_var_7)
	) `HappyStk` happyRest

happyReduce_33 = happySpecReduce_0  36 happyReduction_33
happyReduction_33  =  HappyAbsSyn36
		 ([]
	)

happyReduce_34 = happySpecReduce_2  36 happyReduction_34
happyReduction_34 (HappyAbsSyn35  happy_var_2)
	(HappyAbsSyn36  happy_var_1)
	 =  HappyAbsSyn36
		 (flip (:) happy_var_1 happy_var_2
	)
happyReduction_34 _ _  = notHappyAtAll 

happyReduce_35 = happySpecReduce_0  37 happyReduction_35
happyReduction_35  =  HappyAbsSyn37
		 ([]
	)

happyReduce_36 = happySpecReduce_2  37 happyReduction_36
happyReduction_36 (HappyAbsSyn41  happy_var_2)
	(HappyAbsSyn37  happy_var_1)
	 =  HappyAbsSyn37
		 (flip (:) happy_var_1 happy_var_2
	)
happyReduction_36 _ _  = notHappyAtAll 

happyReduce_37 = happySpecReduce_0  38 happyReduction_37
happyReduction_37  =  HappyAbsSyn38
		 ([]
	)

happyReduce_38 = happySpecReduce_1  38 happyReduction_38
happyReduction_38 (HappyAbsSyn42  happy_var_1)
	 =  HappyAbsSyn38
		 ((:[]) happy_var_1
	)
happyReduction_38 _  = notHappyAtAll 

happyReduce_39 = happySpecReduce_3  38 happyReduction_39
happyReduction_39 (HappyAbsSyn38  happy_var_3)
	_
	(HappyAbsSyn42  happy_var_1)
	 =  HappyAbsSyn38
		 ((:) happy_var_1 happy_var_3
	)
happyReduction_39 _ _ _  = notHappyAtAll 

happyReduce_40 = happySpecReduce_1  39 happyReduction_40
happyReduction_40 (HappyAbsSyn33  happy_var_1)
	 =  HappyAbsSyn39
		 ((:[]) happy_var_1
	)
happyReduction_40 _  = notHappyAtAll 

happyReduce_41 = happySpecReduce_3  39 happyReduction_41
happyReduction_41 (HappyAbsSyn39  happy_var_3)
	_
	(HappyAbsSyn33  happy_var_1)
	 =  HappyAbsSyn39
		 ((:) happy_var_1 happy_var_3
	)
happyReduction_41 _ _ _  = notHappyAtAll 

happyReduce_42 = happySpecReduce_1  40 happyReduction_42
happyReduction_42 _
	 =  HappyAbsSyn40
		 (AbsCPP.Tbool
	)

happyReduce_43 = happySpecReduce_1  40 happyReduction_43
happyReduction_43 _
	 =  HappyAbsSyn40
		 (AbsCPP.Tdouble
	)

happyReduce_44 = happySpecReduce_1  40 happyReduction_44
happyReduction_44 _
	 =  HappyAbsSyn40
		 (AbsCPP.Tint
	)

happyReduce_45 = happySpecReduce_1  40 happyReduction_45
happyReduction_45 _
	 =  HappyAbsSyn40
		 (AbsCPP.Tstring
	)

happyReduce_46 = happySpecReduce_1  40 happyReduction_46
happyReduction_46 _
	 =  HappyAbsSyn40
		 (AbsCPP.Tvoid
	)

happyReduce_47 = happySpecReduce_2  41 happyReduction_47
happyReduction_47 _
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn41
		 (AbsCPP.SExp happy_var_1
	)
happyReduction_47 _ _  = notHappyAtAll 

happyReduce_48 = happySpecReduce_3  41 happyReduction_48
happyReduction_48 _
	(HappyAbsSyn33  happy_var_2)
	(HappyAbsSyn40  happy_var_1)
	 =  HappyAbsSyn41
		 (AbsCPP.SDecl happy_var_1 happy_var_2
	)
happyReduction_48 _ _ _  = notHappyAtAll 

happyReduce_49 = happyReduce 5 41 happyReduction_49
happyReduction_49 (_ `HappyStk`
	(HappyAbsSyn39  happy_var_4) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn33  happy_var_2) `HappyStk`
	(HappyAbsSyn40  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn41
		 (AbsCPP.SDecls happy_var_1 happy_var_2 happy_var_4
	) `HappyStk` happyRest

happyReduce_50 = happyReduce 5 41 happyReduction_50
happyReduction_50 (_ `HappyStk`
	(HappyAbsSyn43  happy_var_4) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn33  happy_var_2) `HappyStk`
	(HappyAbsSyn40  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn41
		 (AbsCPP.SInit happy_var_1 happy_var_2 happy_var_4
	) `HappyStk` happyRest

happyReduce_51 = happySpecReduce_3  41 happyReduction_51
happyReduction_51 _
	(HappyAbsSyn43  happy_var_2)
	_
	 =  HappyAbsSyn41
		 (AbsCPP.SReturn happy_var_2
	)
happyReduction_51 _ _ _  = notHappyAtAll 

happyReduce_52 = happyReduce 5 41 happyReduction_52
happyReduction_52 ((HappyAbsSyn41  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn43  happy_var_3) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn41
		 (AbsCPP.SWhile happy_var_3 happy_var_5
	) `HappyStk` happyRest

happyReduce_53 = happySpecReduce_3  41 happyReduction_53
happyReduction_53 _
	(HappyAbsSyn37  happy_var_2)
	_
	 =  HappyAbsSyn41
		 (AbsCPP.SBlock (reverse happy_var_2)
	)
happyReduction_53 _ _ _  = notHappyAtAll 

happyReduce_54 = happyReduce 7 41 happyReduction_54
happyReduction_54 ((HappyAbsSyn41  happy_var_7) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn41  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn43  happy_var_3) `HappyStk`
	_ `HappyStk`
	_ `HappyStk`
	happyRest)
	 = HappyAbsSyn41
		 (AbsCPP.SIfElse happy_var_3 happy_var_5 happy_var_7
	) `HappyStk` happyRest

happyReduce_55 = happySpecReduce_2  42 happyReduction_55
happyReduction_55 (HappyAbsSyn33  happy_var_2)
	(HappyAbsSyn40  happy_var_1)
	 =  HappyAbsSyn42
		 (AbsCPP.ADecl happy_var_1 happy_var_2
	)
happyReduction_55 _ _  = notHappyAtAll 

happyReduce_56 = happySpecReduce_1  43 happyReduction_56
happyReduction_56 (HappyAbsSyn30  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EInt happy_var_1
	)
happyReduction_56 _  = notHappyAtAll 

happyReduce_57 = happySpecReduce_1  43 happyReduction_57
happyReduction_57 (HappyAbsSyn31  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EDouble happy_var_1
	)
happyReduction_57 _  = notHappyAtAll 

happyReduce_58 = happySpecReduce_1  43 happyReduction_58
happyReduction_58 (HappyAbsSyn32  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EString happy_var_1
	)
happyReduction_58 _  = notHappyAtAll 

happyReduce_59 = happySpecReduce_1  43 happyReduction_59
happyReduction_59 _
	 =  HappyAbsSyn43
		 (AbsCPP.ETrue
	)

happyReduce_60 = happySpecReduce_1  43 happyReduction_60
happyReduction_60 _
	 =  HappyAbsSyn43
		 (AbsCPP.EFalse
	)

happyReduce_61 = happySpecReduce_1  43 happyReduction_61
happyReduction_61 (HappyAbsSyn33  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EId happy_var_1
	)
happyReduction_61 _  = notHappyAtAll 

happyReduce_62 = happySpecReduce_3  43 happyReduction_62
happyReduction_62 _
	(HappyAbsSyn43  happy_var_2)
	_
	 =  HappyAbsSyn43
		 (happy_var_2
	)
happyReduction_62 _ _ _  = notHappyAtAll 

happyReduce_63 = happyReduce 4 44 happyReduction_63
happyReduction_63 (_ `HappyStk`
	(HappyAbsSyn60  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn33  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn43
		 (AbsCPP.ECall happy_var_1 happy_var_3
	) `HappyStk` happyRest

happyReduce_64 = happySpecReduce_3  44 happyReduction_64
happyReduction_64 (HappyAbsSyn33  happy_var_3)
	_
	(HappyAbsSyn33  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EIndex happy_var_1 happy_var_3
	)
happyReduction_64 _ _ _  = notHappyAtAll 

happyReduce_65 = happyReduce 4 44 happyReduction_65
happyReduction_65 (_ `HappyStk`
	(HappyAbsSyn33  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn33  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn43
		 (AbsCPP.EQuali happy_var_1 happy_var_3
	) `HappyStk` happyRest

happyReduce_66 = happySpecReduce_1  44 happyReduction_66
happyReduction_66 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_66 _  = notHappyAtAll 

happyReduce_67 = happySpecReduce_2  45 happyReduction_67
happyReduction_67 _
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EPIncr happy_var_1
	)
happyReduction_67 _ _  = notHappyAtAll 

happyReduce_68 = happySpecReduce_2  45 happyReduction_68
happyReduction_68 _
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EPDecr happy_var_1
	)
happyReduction_68 _ _  = notHappyAtAll 

happyReduce_69 = happySpecReduce_2  45 happyReduction_69
happyReduction_69 (HappyAbsSyn33  happy_var_2)
	_
	 =  HappyAbsSyn43
		 (AbsCPP.EDeref happy_var_2
	)
happyReduction_69 _ _  = notHappyAtAll 

happyReduce_70 = happySpecReduce_3  45 happyReduction_70
happyReduction_70 (HappyAbsSyn33  happy_var_3)
	_
	(HappyAbsSyn33  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EDot happy_var_1 happy_var_3
	)
happyReduction_70 _ _ _  = notHappyAtAll 

happyReduce_71 = happySpecReduce_3  45 happyReduction_71
happyReduction_71 (HappyAbsSyn33  happy_var_3)
	_
	(HappyAbsSyn33  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EArrow happy_var_1 happy_var_3
	)
happyReduction_71 _ _ _  = notHappyAtAll 

happyReduce_72 = happySpecReduce_1  45 happyReduction_72
happyReduction_72 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_72 _  = notHappyAtAll 

happyReduce_73 = happySpecReduce_2  46 happyReduction_73
happyReduction_73 (HappyAbsSyn43  happy_var_2)
	_
	 =  HappyAbsSyn43
		 (AbsCPP.EIncr happy_var_2
	)
happyReduction_73 _ _  = notHappyAtAll 

happyReduce_74 = happySpecReduce_2  46 happyReduction_74
happyReduction_74 (HappyAbsSyn43  happy_var_2)
	_
	 =  HappyAbsSyn43
		 (AbsCPP.EDecr happy_var_2
	)
happyReduction_74 _ _  = notHappyAtAll 

happyReduce_75 = happySpecReduce_2  46 happyReduction_75
happyReduction_75 (HappyAbsSyn43  happy_var_2)
	_
	 =  HappyAbsSyn43
		 (AbsCPP.ELogNeg happy_var_2
	)
happyReduction_75 _ _  = notHappyAtAll 

happyReduce_76 = happySpecReduce_2  46 happyReduction_76
happyReduction_76 (HappyAbsSyn43  happy_var_2)
	_
	 =  HappyAbsSyn43
		 (AbsCPP.ENeg happy_var_2
	)
happyReduction_76 _ _  = notHappyAtAll 

happyReduce_77 = happySpecReduce_1  46 happyReduction_77
happyReduction_77 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_77 _  = notHappyAtAll 

happyReduce_78 = happySpecReduce_3  47 happyReduction_78
happyReduction_78 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EMul happy_var_1 happy_var_3
	)
happyReduction_78 _ _ _  = notHappyAtAll 

happyReduce_79 = happySpecReduce_3  47 happyReduction_79
happyReduction_79 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EDiv happy_var_1 happy_var_3
	)
happyReduction_79 _ _ _  = notHappyAtAll 

happyReduce_80 = happySpecReduce_3  47 happyReduction_80
happyReduction_80 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EMod happy_var_1 happy_var_3
	)
happyReduction_80 _ _ _  = notHappyAtAll 

happyReduce_81 = happySpecReduce_1  47 happyReduction_81
happyReduction_81 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_81 _  = notHappyAtAll 

happyReduce_82 = happySpecReduce_3  48 happyReduction_82
happyReduction_82 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EAdd happy_var_1 happy_var_3
	)
happyReduction_82 _ _ _  = notHappyAtAll 

happyReduce_83 = happySpecReduce_3  48 happyReduction_83
happyReduction_83 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.ESub happy_var_1 happy_var_3
	)
happyReduction_83 _ _ _  = notHappyAtAll 

happyReduce_84 = happySpecReduce_1  48 happyReduction_84
happyReduction_84 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_84 _  = notHappyAtAll 

happyReduce_85 = happySpecReduce_3  49 happyReduction_85
happyReduction_85 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.ELShift happy_var_1 happy_var_3
	)
happyReduction_85 _ _ _  = notHappyAtAll 

happyReduce_86 = happySpecReduce_3  49 happyReduction_86
happyReduction_86 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.ERShift happy_var_1 happy_var_3
	)
happyReduction_86 _ _ _  = notHappyAtAll 

happyReduce_87 = happySpecReduce_1  49 happyReduction_87
happyReduction_87 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_87 _  = notHappyAtAll 

happyReduce_88 = happySpecReduce_3  50 happyReduction_88
happyReduction_88 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.ESm happy_var_1 happy_var_3
	)
happyReduction_88 _ _ _  = notHappyAtAll 

happyReduce_89 = happySpecReduce_3  50 happyReduction_89
happyReduction_89 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EGt happy_var_1 happy_var_3
	)
happyReduction_89 _ _ _  = notHappyAtAll 

happyReduce_90 = happySpecReduce_3  50 happyReduction_90
happyReduction_90 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.ESmEq happy_var_1 happy_var_3
	)
happyReduction_90 _ _ _  = notHappyAtAll 

happyReduce_91 = happySpecReduce_3  50 happyReduction_91
happyReduction_91 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EGtEq happy_var_1 happy_var_3
	)
happyReduction_91 _ _ _  = notHappyAtAll 

happyReduce_92 = happySpecReduce_1  50 happyReduction_92
happyReduction_92 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_92 _  = notHappyAtAll 

happyReduce_93 = happySpecReduce_3  51 happyReduction_93
happyReduction_93 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EEq happy_var_1 happy_var_3
	)
happyReduction_93 _ _ _  = notHappyAtAll 

happyReduce_94 = happySpecReduce_3  51 happyReduction_94
happyReduction_94 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.ENEq happy_var_1 happy_var_3
	)
happyReduction_94 _ _ _  = notHappyAtAll 

happyReduce_95 = happySpecReduce_1  51 happyReduction_95
happyReduction_95 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_95 _  = notHappyAtAll 

happyReduce_96 = happySpecReduce_3  52 happyReduction_96
happyReduction_96 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EAnd happy_var_1 happy_var_3
	)
happyReduction_96 _ _ _  = notHappyAtAll 

happyReduce_97 = happySpecReduce_1  52 happyReduction_97
happyReduction_97 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_97 _  = notHappyAtAll 

happyReduce_98 = happySpecReduce_3  53 happyReduction_98
happyReduction_98 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EOr happy_var_1 happy_var_3
	)
happyReduction_98 _ _ _  = notHappyAtAll 

happyReduce_99 = happySpecReduce_1  53 happyReduction_99
happyReduction_99 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_99 _  = notHappyAtAll 

happyReduce_100 = happySpecReduce_3  54 happyReduction_100
happyReduction_100 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EAss happy_var_1 happy_var_3
	)
happyReduction_100 _ _ _  = notHappyAtAll 

happyReduce_101 = happySpecReduce_3  54 happyReduction_101
happyReduction_101 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EAssPlus happy_var_1 happy_var_3
	)
happyReduction_101 _ _ _  = notHappyAtAll 

happyReduce_102 = happySpecReduce_3  54 happyReduction_102
happyReduction_102 (HappyAbsSyn43  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (AbsCPP.EAssMinus happy_var_1 happy_var_3
	)
happyReduction_102 _ _ _  = notHappyAtAll 

happyReduce_103 = happyReduce 5 54 happyReduction_103
happyReduction_103 ((HappyAbsSyn41  happy_var_5) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn41  happy_var_3) `HappyStk`
	_ `HappyStk`
	(HappyAbsSyn43  happy_var_1) `HappyStk`
	happyRest)
	 = HappyAbsSyn43
		 (AbsCPP.ECond happy_var_1 happy_var_3 happy_var_5
	) `HappyStk` happyRest

happyReduce_104 = happySpecReduce_1  54 happyReduction_104
happyReduction_104 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_104 _  = notHappyAtAll 

happyReduce_105 = happySpecReduce_1  55 happyReduction_105
happyReduction_105 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_105 _  = notHappyAtAll 

happyReduce_106 = happySpecReduce_1  56 happyReduction_106
happyReduction_106 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_106 _  = notHappyAtAll 

happyReduce_107 = happySpecReduce_1  57 happyReduction_107
happyReduction_107 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_107 _  = notHappyAtAll 

happyReduce_108 = happySpecReduce_1  58 happyReduction_108
happyReduction_108 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_108 _  = notHappyAtAll 

happyReduce_109 = happySpecReduce_1  59 happyReduction_109
happyReduction_109 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn43
		 (happy_var_1
	)
happyReduction_109 _  = notHappyAtAll 

happyReduce_110 = happySpecReduce_0  60 happyReduction_110
happyReduction_110  =  HappyAbsSyn60
		 ([]
	)

happyReduce_111 = happySpecReduce_1  60 happyReduction_111
happyReduction_111 (HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn60
		 ((:[]) happy_var_1
	)
happyReduction_111 _  = notHappyAtAll 

happyReduce_112 = happySpecReduce_3  60 happyReduction_112
happyReduction_112 (HappyAbsSyn60  happy_var_3)
	_
	(HappyAbsSyn43  happy_var_1)
	 =  HappyAbsSyn60
		 ((:) happy_var_1 happy_var_3
	)
happyReduction_112 _ _ _  = notHappyAtAll 

happyNewToken action sts stk [] =
	action 111 111 notHappyAtAll (HappyState action) sts stk []

happyNewToken action sts stk (tk:tks) =
	let cont i = action i i tk (HappyState action) sts stk tks in
	case tk of {
	PT _ (TS _ 1) -> cont 61;
	PT _ (TS _ 2) -> cont 62;
	PT _ (TS _ 3) -> cont 63;
	PT _ (TS _ 4) -> cont 64;
	PT _ (TS _ 5) -> cont 65;
	PT _ (TS _ 6) -> cont 66;
	PT _ (TS _ 7) -> cont 67;
	PT _ (TS _ 8) -> cont 68;
	PT _ (TS _ 9) -> cont 69;
	PT _ (TS _ 10) -> cont 70;
	PT _ (TS _ 11) -> cont 71;
	PT _ (TS _ 12) -> cont 72;
	PT _ (TS _ 13) -> cont 73;
	PT _ (TS _ 14) -> cont 74;
	PT _ (TS _ 15) -> cont 75;
	PT _ (TS _ 16) -> cont 76;
	PT _ (TS _ 17) -> cont 77;
	PT _ (TS _ 18) -> cont 78;
	PT _ (TS _ 19) -> cont 79;
	PT _ (TS _ 20) -> cont 80;
	PT _ (TS _ 21) -> cont 81;
	PT _ (TS _ 22) -> cont 82;
	PT _ (TS _ 23) -> cont 83;
	PT _ (TS _ 24) -> cont 84;
	PT _ (TS _ 25) -> cont 85;
	PT _ (TS _ 26) -> cont 86;
	PT _ (TS _ 27) -> cont 87;
	PT _ (TS _ 28) -> cont 88;
	PT _ (TS _ 29) -> cont 89;
	PT _ (TS _ 30) -> cont 90;
	PT _ (TS _ 31) -> cont 91;
	PT _ (TS _ 32) -> cont 92;
	PT _ (TS _ 33) -> cont 93;
	PT _ (TS _ 34) -> cont 94;
	PT _ (TS _ 35) -> cont 95;
	PT _ (TS _ 36) -> cont 96;
	PT _ (TS _ 37) -> cont 97;
	PT _ (TS _ 38) -> cont 98;
	PT _ (TS _ 39) -> cont 99;
	PT _ (TS _ 40) -> cont 100;
	PT _ (TS _ 41) -> cont 101;
	PT _ (TS _ 42) -> cont 102;
	PT _ (TS _ 43) -> cont 103;
	PT _ (TS _ 44) -> cont 104;
	PT _ (TS _ 45) -> cont 105;
	PT _ (TS _ 46) -> cont 106;
	PT _ (TI happy_dollar_dollar) -> cont 107;
	PT _ (TD happy_dollar_dollar) -> cont 108;
	PT _ (TL happy_dollar_dollar) -> cont 109;
	PT _ (T_Id happy_dollar_dollar) -> cont 110;
	_ -> happyError' (tk:tks)
	}

happyError_ 111 tk tks = happyError' tks
happyError_ _ tk tks = happyError' (tk:tks)

happyThen :: () => Err a -> (a -> Err b) -> Err b
happyThen = (thenM)
happyReturn :: () => a -> Err a
happyReturn = (returnM)
happyThen1 m k tks = (thenM) m (\a -> k a tks)
happyReturn1 :: () => a -> b -> Err a
happyReturn1 = \a tks -> (returnM) a
happyError' :: () => [(Token)] -> Err a
happyError' = happyError

pProgram tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_0 tks) (\x -> case x of {HappyAbsSyn34 z -> happyReturn z; _other -> notHappyAtAll })

pDef tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_1 tks) (\x -> case x of {HappyAbsSyn35 z -> happyReturn z; _other -> notHappyAtAll })

pListDef tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_2 tks) (\x -> case x of {HappyAbsSyn36 z -> happyReturn z; _other -> notHappyAtAll })

pListStm tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_3 tks) (\x -> case x of {HappyAbsSyn37 z -> happyReturn z; _other -> notHappyAtAll })

pListArg tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_4 tks) (\x -> case x of {HappyAbsSyn38 z -> happyReturn z; _other -> notHappyAtAll })

pListId tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_5 tks) (\x -> case x of {HappyAbsSyn39 z -> happyReturn z; _other -> notHappyAtAll })

pType tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_6 tks) (\x -> case x of {HappyAbsSyn40 z -> happyReturn z; _other -> notHappyAtAll })

pStm tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_7 tks) (\x -> case x of {HappyAbsSyn41 z -> happyReturn z; _other -> notHappyAtAll })

pArg tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_8 tks) (\x -> case x of {HappyAbsSyn42 z -> happyReturn z; _other -> notHappyAtAll })

pExp16 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_9 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp15 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_10 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp14 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_11 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp13 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_12 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp12 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_13 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp11 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_14 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp10 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_15 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp9 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_16 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp8 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_17 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp4 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_18 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp3 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_19 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp2 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_20 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_21 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp1 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_22 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp5 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_23 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp6 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_24 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pExp7 tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_25 tks) (\x -> case x of {HappyAbsSyn43 z -> happyReturn z; _other -> notHappyAtAll })

pListExp tks = happySomeParser where
  happySomeParser = happyThen (happyParse action_26 tks) (\x -> case x of {HappyAbsSyn60 z -> happyReturn z; _other -> notHappyAtAll })

happySeq = happyDontSeq


returnM :: a -> Err a
returnM = return

thenM :: Err a -> (a -> Err b) -> Err b
thenM = (>>=)

happyError :: [Token] -> Err a
happyError ts =
  Bad $ "syntax error at " ++ tokenPos ts ++ 
  case ts of
    [] -> []
    [Err _] -> " due to lexer error"
    _ -> " before " ++ unwords (map (id . prToken) (take 4 ts))

myLexer = tokens
{-# LINE 1 "templates/GenericTemplate.hs" #-}
{-# LINE 1 "templates/GenericTemplate.hs" #-}
{-# LINE 1 "<built-in>" #-}
{-# LINE 16 "<built-in>" #-}
{-# LINE 1 "/usr/local/Cellar/ghc/7.10.2/lib/ghc-7.10.2/include/ghcversion.h" #-}


















{-# LINE 17 "<built-in>" #-}
{-# LINE 1 "templates/GenericTemplate.hs" #-}
-- Id: GenericTemplate.hs,v 1.26 2005/01/14 14:47:22 simonmar Exp 


{-# LINE 13 "templates/GenericTemplate.hs" #-}


{-# LINE 46 "templates/GenericTemplate.hs" #-}









{-# LINE 67 "templates/GenericTemplate.hs" #-}


{-# LINE 77 "templates/GenericTemplate.hs" #-}










infixr 9 `HappyStk`
data HappyStk a = HappyStk a (HappyStk a)

-----------------------------------------------------------------------------
-- starting the parse

happyParse start_state = happyNewToken start_state notHappyAtAll notHappyAtAll

-----------------------------------------------------------------------------
-- Accepting the parse

-- If the current token is (1), it means we've just accepted a partial
-- parse (a %partial parser).  We must ignore the saved token on the top of
-- the stack in this case.
happyAccept (1) tk st sts (_ `HappyStk` ans `HappyStk` _) =
        happyReturn1 ans
happyAccept j tk st sts (HappyStk ans _) = 
         (happyReturn1 ans)

-----------------------------------------------------------------------------
-- Arrays only: do the next action


{-# LINE 155 "templates/GenericTemplate.hs" #-}

-----------------------------------------------------------------------------
-- HappyState data type (not arrays)



newtype HappyState b c = HappyState
        (Int ->                    -- token number
         Int ->                    -- token number (yes, again)
         b ->                           -- token semantic value
         HappyState b c ->              -- current state
         [HappyState b c] ->            -- state stack
         c)



-----------------------------------------------------------------------------
-- Shifting a token

happyShift new_state (1) tk st sts stk@(x `HappyStk` _) =
     let i = (case x of { HappyErrorToken (i) -> i }) in
--     trace "shifting the error token" $
     new_state i i tk (HappyState (new_state)) ((st):(sts)) (stk)

happyShift new_state i tk st sts stk =
     happyNewToken new_state ((st):(sts)) ((HappyTerminal (tk))`HappyStk`stk)

-- happyReduce is specialised for the common cases.

happySpecReduce_0 i fn (1) tk st sts stk
     = happyFail (1) tk st sts stk
happySpecReduce_0 nt fn j tk st@((HappyState (action))) sts stk
     = action nt j tk st ((st):(sts)) (fn `HappyStk` stk)

happySpecReduce_1 i fn (1) tk st sts stk
     = happyFail (1) tk st sts stk
happySpecReduce_1 nt fn j tk _ sts@(((st@(HappyState (action))):(_))) (v1`HappyStk`stk')
     = let r = fn v1 in
       happySeq r (action nt j tk st sts (r `HappyStk` stk'))

happySpecReduce_2 i fn (1) tk st sts stk
     = happyFail (1) tk st sts stk
happySpecReduce_2 nt fn j tk _ ((_):(sts@(((st@(HappyState (action))):(_))))) (v1`HappyStk`v2`HappyStk`stk')
     = let r = fn v1 v2 in
       happySeq r (action nt j tk st sts (r `HappyStk` stk'))

happySpecReduce_3 i fn (1) tk st sts stk
     = happyFail (1) tk st sts stk
happySpecReduce_3 nt fn j tk _ ((_):(((_):(sts@(((st@(HappyState (action))):(_))))))) (v1`HappyStk`v2`HappyStk`v3`HappyStk`stk')
     = let r = fn v1 v2 v3 in
       happySeq r (action nt j tk st sts (r `HappyStk` stk'))

happyReduce k i fn (1) tk st sts stk
     = happyFail (1) tk st sts stk
happyReduce k nt fn j tk st sts stk
     = case happyDrop (k - ((1) :: Int)) sts of
         sts1@(((st1@(HappyState (action))):(_))) ->
                let r = fn stk in  -- it doesn't hurt to always seq here...
                happyDoSeq r (action nt j tk st1 sts1 r)

happyMonadReduce k nt fn (1) tk st sts stk
     = happyFail (1) tk st sts stk
happyMonadReduce k nt fn j tk st sts stk =
      case happyDrop k ((st):(sts)) of
        sts1@(((st1@(HappyState (action))):(_))) ->
          let drop_stk = happyDropStk k stk in
          happyThen1 (fn stk tk) (\r -> action nt j tk st1 sts1 (r `HappyStk` drop_stk))

happyMonad2Reduce k nt fn (1) tk st sts stk
     = happyFail (1) tk st sts stk
happyMonad2Reduce k nt fn j tk st sts stk =
      case happyDrop k ((st):(sts)) of
        sts1@(((st1@(HappyState (action))):(_))) ->
         let drop_stk = happyDropStk k stk





             new_state = action

          in
          happyThen1 (fn stk tk) (\r -> happyNewToken new_state sts1 (r `HappyStk` drop_stk))

happyDrop (0) l = l
happyDrop n ((_):(t)) = happyDrop (n - ((1) :: Int)) t

happyDropStk (0) l = l
happyDropStk n (x `HappyStk` xs) = happyDropStk (n - ((1)::Int)) xs

-----------------------------------------------------------------------------
-- Moving to a new state after a reduction









happyGoto action j tk st = action j j tk (HappyState action)


-----------------------------------------------------------------------------
-- Error recovery ((1) is the error token)

-- parse error if we are in recovery and we fail again
happyFail (1) tk old_st _ stk@(x `HappyStk` _) =
     let i = (case x of { HappyErrorToken (i) -> i }) in
--      trace "failing" $ 
        happyError_ i tk

{-  We don't need state discarding for our restricted implementation of
    "error".  In fact, it can cause some bogus parses, so I've disabled it
    for now --SDM

-- discard a state
happyFail  (1) tk old_st (((HappyState (action))):(sts)) 
                                                (saved_tok `HappyStk` _ `HappyStk` stk) =
--      trace ("discarding state, depth " ++ show (length stk))  $
        action (1) (1) tk (HappyState (action)) sts ((saved_tok`HappyStk`stk))
-}

-- Enter error recovery: generate an error token,
--                       save the old token and carry on.
happyFail  i tk (HappyState (action)) sts stk =
--      trace "entering error recovery" $
        action (1) (1) tk (HappyState (action)) sts ( (HappyErrorToken (i)) `HappyStk` stk)

-- Internal happy errors:

notHappyAtAll :: a
notHappyAtAll = error "Internal Happy error\n"

-----------------------------------------------------------------------------
-- Hack to get the typechecker to accept our action functions







-----------------------------------------------------------------------------
-- Seq-ing.  If the --strict flag is given, then Happy emits 
--      happySeq = happyDoSeq
-- otherwise it emits
--      happySeq = happyDontSeq

happyDoSeq, happyDontSeq :: a -> b -> b
happyDoSeq   a b = a `seq` b
happyDontSeq a b = b

-----------------------------------------------------------------------------
-- Don't inline any functions from the template.  GHC has a nasty habit
-- of deciding to inline happyGoto everywhere, which increases the size of
-- the generated parser quite a bit.









{-# NOINLINE happyShift #-}
{-# NOINLINE happySpecReduce_0 #-}
{-# NOINLINE happySpecReduce_1 #-}
{-# NOINLINE happySpecReduce_2 #-}
{-# NOINLINE happySpecReduce_3 #-}
{-# NOINLINE happyReduce #-}
{-# NOINLINE happyMonadReduce #-}
{-# NOINLINE happyGoto #-}
{-# NOINLINE happyFail #-}

-- end of Happy Template.

