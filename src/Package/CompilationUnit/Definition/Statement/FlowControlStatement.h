#pragma once

#include "StatementHasKind.h"
#include "../../../../Token/TokenKeyword.h"

enum StatementFlowControlType
{
    STATEMENT_FLOW_CONTROL_BREAK = TOKEN_KEYWORD_BREAK,
    STATEMENT_FLOW_CONTROL_CONTINUE = TOKEN_KEYWORD_CONTINUE,
    STATEMENT_FLOW_CONTROL_RETURN = TOKEN_KEYWORD_RETURN,
    STATEMENT_FLOW_CONTROL_THROW = TOKEN_KEYWORD_THROW
};

class FlowControlStatement : public StatementHasKind<StatementFlowControlType>
{
    public:
        FlowControlStatement(StatementFlowControlType kind);

        StatementType getType()
        {
            return STATEMENT_FLOW_CONTROL;
        }

        static string getPrintableKindString(StatementFlowControlType kind);
        string getPrintableKindString();
};