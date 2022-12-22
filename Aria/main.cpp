#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>

#include "scanner.h"
#include "parser.h"
#include "ast.h"
#include "visitor.h"

using namespace std;

void scan_tokens(string);

int main()
{
	Scanner scanner("!.aria");
	std::vector<Token> tokens = scanner.Scan();

	Parser parser(tokens);
	std::unique_ptr<ExprAST> ast = parser.GenAST();

	PrinterVisitor ASTPrinter;
	ast->Accept(&ASTPrinter);
}