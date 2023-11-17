#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../../backend/semantic-analysis/abstract-syntax-tree.h"

/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */

// Programa.
 Program * ProgramGrammarAction(MeshItemNode * meshes);

//Function
FunctionNode * FunctionParamsGrammarAction(FunctionNode * first, FunctionNode * second);

FunctionNode * FunctionGrammarAction(MeshItemNode * mesh);

MeshItem FunctionNodeToMeshItem(FunctionNode * functionNode);

// Component.
Component * ComponentGrammarAction(const ComponentType value, const Color color, ComponentParamsList * params);

// Params.
ComponentParamsList * ComponentParamsGrammarAction(ComponentParams params, const ParamType paramType);

// Pair
Pair * PairGrammarAction(Value leftValue, ValueType type, Value rightValue);

// Constantes.
Constant * ConstantGrammarAction(Value value, ValueType type);

// Meshes
MeshItemNode * MeshGrammarAction(MeshItem meshItem, MeshItemType type, Color color);

MeshItemNode * MeshesGrammarAction(MeshItemNode * first, MeshItemNode * second);

PairNode * PairsGrammarAction(Pair * first, PairNode * second);

int VariablesGrammarAction(const int value);

int IdentifierVariableGrammarAction(const int value);


#endif
