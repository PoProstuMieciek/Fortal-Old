#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(shared_ptr<Modifiers> modifiers, shared_ptr<DataType> return_type, shared_ptr<TokenIdentifier> identifier) : Definition(modifiers, identifier)
{
    this->return_type = return_type;
}

shared_ptr<DataType> FunctionDefinition::getReturnType()
{
    return return_type;
}

void FunctionDefinition::addParameter(shared_ptr<VariableDefinition> definition)
{
    this->parameters.push_back(definition);
}

void FunctionDefinition::addParameters(vector<shared_ptr<VariableDefinition>> definitions)
{
    for (auto def : definitions)
    {
        addParameter(def);
    }
}

vector<shared_ptr<VariableDefinition>> FunctionDefinition::getParameters()
{
    return parameters;
}

shared_ptr<BlockStatement> FunctionDefinition::getBody()
{
    return body;
}

void FunctionDefinition::setBody(shared_ptr<BlockStatement> body)
{
    this->body = body;
}

string FunctionDefinition::getDebug(string indent, bool last, string custom)
{
    custom = return_type->toString();
    custom += " ";
    custom += getIdentifier()->getName();
    custom += "(";

    for (size_t i = 0; i < parameters.size(); i++)
    {
        bool isLast = (i + 1 == parameters.size());

        auto param = parameters[i];
        custom += param->getFunctionParamDebug(isLast);
    }

    custom += ")";

    string output = Definition::getDebug(indent, last, custom);

    if (last)
    {
        indent += "    ";
    }
    else
    {
        indent += "│   ";
    }

    output += body->getDebug(indent);

    return output;
}