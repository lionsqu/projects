//版权所有©: 2018 瞿正峰（Lions）
//未经书面授权，商业性组织不得销售或赠送本代码以及本代码的衍生代码，编译的中间产物和可执行文件，以及各类文档。
//邮箱:lionsqu@yahoo.com
//
#ifndef QUPAINTXMLFILE_H
#define QUPAINTXMLFILE_H
#include <string>


class QuPaintXmlFile
{
    public:
        QuPaintXmlFile(std::wstring path, std::wstring filename);
        virtual ~QuPaintXmlFile();

    public:
        int Load();
        int Save();

    protected:
    private:
};

#endif // QUPAINTXMLFILE_H
