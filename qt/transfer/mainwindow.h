#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "common/HttpFun.h"

namespace Ui {
class MainWindow;
}

// 总进度
enum class Progress {
    Nothing              = 0,
    PlanInfo             = 1,
    PlanRegHistory       = 2,
    PlanRegIncrement     = 3
};

// 分进度
enum class ProgressItem {
    Nothing               = 0,
    Transfer              = 1,
    Verivy                = 2,
    Rollback              = 3 // 暂时用不到
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btn_transfer_plan_info_clicked();

    void on_btn_verify_plan_info_clicked();

    void on_btn_rollback_plan_info_clicked();

    void on_btn_tranfser_plan_reg_increment_clicked();

    void on_btn_tranfser_plan_reg_history_clicked();

    void on_btn_verify_plan_reg_history_clicked();

    void on_btn_verify_plan_reg_increment_clicked();

    void on_btn_rollback_plan_reg_clicked();

    void slots_transfer_plan_requestFinished( bool bSuccess, const QString& strResult );

private:
    Ui::MainWindow *ui;
    Progress progress;
    ProgressItem progressItem;
    
    // 执行控制器 当前执行的那个步奏的那个动作
    void updateProgress( Progress progress, ProgressItem progressItem );
    QString joinReqUrl( QString& actionName );
};



#endif // MAINWINDOW_H
