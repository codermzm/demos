#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置窗口禁止改变大小
    Qt::WindowFlags flags = Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint;
    // flags |= Qt::WindowMinimizeButtonHint;
    // flags |= Qt::WindowMaximizeButtonHint;
    // flags |= Qt::WindowCloseButtonHint;
    this->setWindowFlags(flags);
    this->setFixedSize( this->width (),this->height ());
    
    // 初始化仪表盘
    this->ui->round_progress_bar_plan_info->setValue( 0 );
    this->ui->round_progress_bar_reg_history->setValue( 0 );
    this->ui->round_progress_bar_reg_increment->setValue( 0 );
    
    QPalette palette;
    palette.setBrush(QPalette::AlternateBase, Qt::black);
    palette.setColor(QPalette::Text, Qt::yellow);
    
    QGradientStops gradientPoints;
    gradientPoints << QGradientStop(0, Qt::green) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);
    
    this->ui->round_progress_bar_plan_info->setPalette(palette);
    this->ui->round_progress_bar_plan_info->setNullPosition(QRoundProgressBar::PositionLeft);
    this->ui->round_progress_bar_plan_info->setDecimals(0);
    this->ui->round_progress_bar_plan_info->setDataColors(gradientPoints);
    
    this->ui->round_progress_bar_reg_history->setPalette(palette);
    this->ui->round_progress_bar_reg_history->setNullPosition(QRoundProgressBar::PositionLeft);
    this->ui->round_progress_bar_reg_history->setDecimals(0);
    this->ui->round_progress_bar_reg_history->setDataColors(gradientPoints);
    
    this->ui->round_progress_bar_reg_increment->setPalette(palette);
    this->ui->round_progress_bar_reg_increment->setNullPosition(QRoundProgressBar::PositionLeft);
    this->ui->round_progress_bar_reg_increment->setDecimals(0);
    this->ui->round_progress_bar_reg_increment->setDataColors(gradientPoints);
    
    
    this->updateProgress( Progress::Nothing, ProgressItem::Nothing );
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 迁移提报基础信息
void MainWindow::on_btn_transfer_plan_info_clicked()
{
    HttpFun *httpFun = new HttpFun( this );
    connect(httpFun,SIGNAL(signal_requestFinished(bool,const QString&)),
            this,SLOT(slots_transfer_plan_requestFinished(bool, const QString&)));
    QString actionUrl( "/mct/cost/task/transfer/planBaseData" );
    QString url = joinReqUrl( actionUrl );
    if ( url.isEmpty( )) {
        return ;
    }

    httpFun->sendRequest( url );

}
// 接受http请求
void MainWindow::slots_transfer_plan_requestFinished( bool bSuccess, const QString& strResult )
{
    if ( bSuccess == false ) {
        QMessageBox::information(this,"错误","请求异常" );
        return;
    }

    ui->txt_result->setText( strResult );
}

void MainWindow::on_btn_verify_plan_info_clicked()
{
    QMessageBox::information( this, "提示", "验证成功" );
}

void MainWindow::on_btn_rollback_plan_info_clicked()
{
    
}

void MainWindow::on_btn_tranfser_plan_reg_increment_clicked()
{

}

void MainWindow::on_btn_tranfser_plan_reg_history_clicked()
{

}

void MainWindow::on_btn_verify_plan_reg_history_clicked()
{

}

void MainWindow::on_btn_verify_plan_reg_increment_clicked()
{

}

void MainWindow::on_btn_rollback_plan_reg_clicked()
{

}


void MainWindow::updateProgress( Progress progress, ProgressItem progressItem ) 
{
    if ( Progress::Nothing == progress ) {
        // QMessageBox::information( this, "progress", "progressItem" );
    } else if ( Progress::PlanInfo == progress ) {
        // QMessageBox::information( this, "PlanInfo", "progressItem" );
    } else if ( Progress::PlanRegHistory == progress ) {
        // QMessageBox::information( this, "PlanRegHistory", "progressItem" );
    } else if ( Progress::PlanRegIncrement == progress ) {
        // QMessageBox::information( this, "PlanRegIncrement", "progressItem" );
    }
}


QString MainWindow::joinReqUrl( QString& actionName )
{
    QString result;
    QString serverUrl = this->ui->txt_servier_url->text( );
    if ( serverUrl.isEmpty( )) {
        QMessageBox::information(this,"错误","服务器路径不能为空" );
        return result;
    }

    result.append( serverUrl );
    if ( result.endsWith( "/" )) {
        result.remove( result.length( ) - 1, 1 );
    }

    if ( actionName.startsWith( "/" )) {
        actionName.remove( 0, 1 );
    }

    result.append( "/" );
    result.append( actionName );

    return result;
}



