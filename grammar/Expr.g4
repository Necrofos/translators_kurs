grammar Expr;

prog
    : expr EOF
    ;

expr
    : addExpr (compOp addExpr)?
    ;

addExpr
    : INT ('+' INT)*
    ;

compOp
    : '<'
    | '>'
    | '='
    | '!='
    ;

INT
    : [0-9]+
    ;

WS
    : [ \t\r\n]+ -> skip
    ;