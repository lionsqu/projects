//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织或者个人不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物或者可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUHASHMAP_H
#define QUHASHMAP_H


#include <functional>
#include <string>
#include <hash_map>
#include <QuEntity.h>



struct string_hash{
    size_t operator()(const std::string &str) const
    {
        return __gnu_cxx::__stl_hash_string(str.c_str());
    }
};


typedef __gnu_cxx::hash_map<std::string, QuEntity *, string_hash> QuHashMap;



#endif // QUHASHMAP_H
