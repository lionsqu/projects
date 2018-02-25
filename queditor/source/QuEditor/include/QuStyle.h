//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUSTYLE_H
#define QUSTYLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#include <FL/Fl.h>
#include <FL/Fl_Text_Buffer.h>
#include <FL/Fl_Text_Display.h>
#include <common.h>
#include <QuCallBack.h>



extern void style_update(int        pos,		// I - Position of update
             int        nInserted,	// I - Number of inserted chars
             int        nDeleted,	// I - Number of deleted chars
             int        /*nRestyled*/,	// I - Number of restyled chars
             const char * /*deletedText*/,// I - Text that was deleted
             void       *cbArg);  	// I - Callback data


extern void
style_parse(const char *text,
            char       *style,
            int        length);

extern "C" {
    int
    compare_keywords(const void *a,
                     const void *b);
}


extern Fl_Text_Buffer     *stylebuf;
extern Fl_Text_Display::Style_Table_Entry styletable[7] ;
extern const char         *code_keywords[];
extern const char         *code_types[] ;




#endif // QUSTYLE_H
