#pragma once

class AST
{
public:
    AST();
    ~AST();
    void addNode(ASTNode *node);
    void print();
};

class ASTNode
{
public:
    virtual ~ASTNode() = default;
};

class ExperssionNode : public ASTNode
{
};

class StatementNode : public ASTNode
{
};

class LetStatementNode : public StatementNode
{
};

class IfStatementNode : public StatementNode
{
};

class WhileStatementNode : public StatementNode
{
};

class ReturnStatementNode : public StatementNode
{
};

class FunctionStatementNode : public StatementNode
{
};

class OperatorNode : public ExperssionNode
{
};

class IdentifierNode : public ExperssionNode
{
};

class NumberNode : public ExperssionNode
{
};

class StringNode : public ExperssionNode
{
};

/*
    Statements
        function
        variable
        if
        else
        while
        for
        return

    Expressions
        Operator, +, -, *, /, literals


*/