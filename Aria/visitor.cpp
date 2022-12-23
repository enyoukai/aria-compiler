#include "visitor.h"

void Visitor::VisitBinaryAST(BinaryAST *ast)
{
}

void Visitor::VisitLiteralAST(LiteralAST *ast)
{
}

void Visitor::VisitVariableAST(VariableAST *ast)
{
}

void Visitor::VisitAssignmentAST(AssignmentAST *ast)
{
}

PrinterVisitor::PrinterVisitor()
{
}

void PrinterVisitor::VisitBinaryAST(BinaryAST *ast)
{
	std::string TOKEN_MAP[] = {"INT_LITERAl", "STRING_LITERAL", "IDENTIFIER", "PLUS", "MINUS", "STAR", "SLASH", "EQUALS"};

	std::cout << "(";
	ast->leftOp->Accept(this);
	std::cout << ", ";
	std::cout << TOKEN_MAP[ast->op.type];
	std::cout << ", ";
	ast->rightOp->Accept(this);
	std::cout << ")";
}

void PrinterVisitor::VisitLiteralAST(LiteralAST *ast)
{
	if (ast->value.type == Token::INT_LITERAL)
		std::cout << std::to_string(ast->value.intLiteral);
	else if (ast->value.type == Token::STRING_LITERAL)
		std::cout << ast->value.stringLiteral;
	else
		std::cerr << "Error printing out invalid type of enum: " + ast->value.type << '\n';
}

void PrinterVisitor::VisitVariableAST(VariableAST *ast)
{
	std::cout << "Variable(" << ast->name.stringLiteral << ")";
}

void PrinterVisitor::VisitAssignmentAST(AssignmentAST *ast)
{
	ast->variable->Accept(this);
	std::cout << " : ";
	ast->value->Accept(this);
	std::cout << '\n';
}

CodeGenVisitor::CodeGenVisitor()
{
}

void CodeGenVisitor::VisitBinaryAST(BinaryAST *ast)
{
}

void CodeGenVisitor::VisitLiteralAST(LiteralAST *ast)
{
}

void CodeGenVisitor::VisitAssignmentAST(AssignmentAST *ast)
{
	// so goofy
	stackPointer += 4;
	asmIR.MOV("DWORD [rbp-" + std::to_string(stackPointer) + "]", "5");
}

void CodeGenVisitor::VisitVariableAST(VariableAST *ast)
{
}

void CodeGenVisitor::OutputASM()
{
	std::cout << asmIR.OutputASM() << '\n';
}