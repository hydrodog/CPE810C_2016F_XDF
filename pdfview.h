#ifndef PDFVIEW_H
#define PDFVIEW_H

#include <QDialog>

namespace Ui {
class PDFview;
}

class PDFview : public QDialog
{
    Q_OBJECT

public:

    explicit PDFview(QWidget *parent = 0);
    ~PDFview();

    void show_file(QRect rect,QString a);

    QString s2q(const std::string &s);
    std::string q2s(const QString &s);

    char check_first_letter_t(std::string a);
    QString analyze(int a[],std::string b);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_open_setting_clicked();

protected:

    void paintEvent(QPaintEvent*);

private:

    Ui::PDFview *ui;
    QString PDFviewname;
    QString PDFsettingname;
    int open_flag=0;
    int open_setting_flag=0;

};

#endif // PDFVIEW_H
