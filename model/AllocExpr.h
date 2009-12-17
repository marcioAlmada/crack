
#ifndef _model_AllocExpr_h_
#define _model_AllocExpr_h_

#include <string>
#include <vector>
#include "Expr.h"

namespace model {

SPUG_RCPTR(AllocExpr);

class AllocExpr : public Expr {
    public:
        AllocExpr(TypeDef *type) : Expr(type) {}
        virtual void emit(Context &context);
};


} // namespace model

#endif