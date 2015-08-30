#ifndef ENUMPARS_HPP
#define ENUMPARS_HPP

enum EinstructionWord{
 ArgInstr , AssignInstr ,
 DoInstr, DoUntilInstr,DoForInstr,  DoForEverInstr ,
 DoWhileInstr,DoToInstr,DoToByInstr,
 ErrorInstr ,  ExprInstr ,ExitInstr,EndOfFileInstr,EndInstr,
 IfInstr  , IfElseInstr,
 LabelInstr ,LeaveInstr ,  LeaveContInstr,
 NopInstr, NoInstr,
 PullInstr,
 ReturnInstr , ReturnOnlyInstr ,
 SayInstr , SelectInstr

}   ;
// all type of tokens

enum EtokenType {
   And, AnyCharacters , AnyCharactersWithSpace, Arg, Array, Assign,
   By,
   Colon ,Comma,  Concat ,
   Div , Do, DoUntil , DoFor , DoForever , DoWhile , DoTo , DoToBy,
   Else, End, Eq, Error, Expose, ExEq, ExOr, Eof, EndOfLine, EndOfFile,Exit,
   For ,ForEver ,FunctionName,
   Ge, Gt,
   If, IfElse,
   Label, Le, Leave, Lparen, Lt,
   Mul, Minus, Mod,
   Name , Ne, NoToken, Not,Nop,
   OrdNumber, Or, Otherwise,
   Plus, Pow, Procedure, Pull,
   Return, Rparen,
   Say, Select,Stem, String, SciNumber, Semicolon,
   Then,To,
   Until,UnaryPlus,UnaryMinus,
   While ,When
   };
enum EProcType{FunctionType,ProcedureType,LabelType,ProcedureWithExposeType};
#endif
