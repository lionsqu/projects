//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#include "QuTreeItem.h"

QuTreeItem::QuTreeItem(const Fl_Tree_Prefs &prefs) :
    Fl_Tree_Item(prefs)
{

}	// CTOR -- backwards compatible
#if FLTK_ABI_VERSION >= 10303
QuTreeItem::QuTreeItem(Fl_Tree *tree) :
    Fl_Tree_Item(tree)
{

}			// CTOR -- ABI 1.3.3+
#endif
QuTreeItem::QuTreeItem(const Fl_Tree_Item *o) :
    Fl_Tree_Item(o)
{
}		// COPY CTOR

QuTreeItem::~QuTreeItem()
{
    //dtor
}
