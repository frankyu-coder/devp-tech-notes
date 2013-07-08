
#include "image_window.h"
#include "transaction_thread.h"
#include "flip_transaction.h"
#include <QStatusBar>
#include <QAction>
#include <QLabel>
#include <QIcon>
#include <QMenuBar>

class ImageWindow::PrivateData
{
    public:
        QAction *openAction;
        QAction *saveAction;
        QAction *saveAsAction;
        QAction *exitAction;
        QAction *flipHorAction;

        QMenu *fileMenu;
        QMenu *editMenu;
        QMenu *helpMenu;

        QLabel  *imageLabel;

        QString file;

        TransactionThread thread;
        //FlipTransaction *flip;
};

ImageWindow::ImageWindow()
{
    m_data = new PrivateData;
    init();
}

ImageWindow::~ImageWindow()
{
    delete m_data;
}

void ImageWindow::init()
{
    QPixmap map;
    map.load(":/images/map.png");
    m_data->imageLabel = new QLabel(this);
//    m_data->imageLabel->setBackgroundRole(QPalette::Dark);
//    m_data->imageLabel->setAutoFillBackground(true);
    m_data->imageLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_data->imageLabel->setPixmap(map);
    setCentralWidget(m_data->imageLabel);

    createActions();
    createMenus();

    statusBar()->showMessage(tr("Ready"), 2000);

    connect(&m_data->thread, SIGNAL(transactionStarted(const QString &)),
            statusBar(), SLOT(showMessage(const QString&)));
    connect(&m_data->thread, SIGNAL(allTransactionsDone()),
            this, SLOT(allTransactionsDone()));

    setCurrentFile("");
}

void ImageWindow::createActions()
{
    m_data->openAction = new QAction(tr("&Open"), this);
    m_data->openAction->setIcon(QIcon(":/images/open.png"));
    m_data->openAction->setShortcut(QKeySequence::Open);
    m_data->openAction->setStatusTip(tr("Open a image"));
    connect(m_data->openAction, SIGNAL(triggered()),
                this, SLOT(openImage()));

    m_data->saveAction = new QAction(tr("&Save"), this);
    m_data->saveAction->setIcon(QIcon(":/images/save.png"));
    m_data->saveAction->setShortcut(QKeySequence::Save);
    m_data->saveAction->setStatusTip(tr("Save a image"));
    connect(m_data->saveAction, SIGNAL(triggered()),
                this, SLOT(saveImage()));

    m_data->saveAsAction = new QAction(tr("Save&As"), this);
    m_data->saveAsAction->setIcon(QIcon(":/images/saveAs.png"));
    m_data->saveAsAction->setShortcut(QKeySequence::SaveAs);
    m_data->saveAsAction->setStatusTip(tr("Save as a image"));
    connect(m_data->saveAsAction, SIGNAL(triggered()),
                this, SLOT(saveAsImage()));

    m_data->exitAction = new QAction(tr("&Exit"), this);
    m_data->exitAction->setIcon(QIcon(":/images/exit.png"));
    m_data->exitAction->setShortcut(QKeySequence::Quit);
    m_data->exitAction->setStatusTip(tr("Exit"));
    connect(m_data->exitAction, SIGNAL(triggered()),
            this, SLOT(exit()));

    m_data->flipHorAction = new QAction(tr("&Flip &Horizontallly"), this);
    m_data->flipHorAction->setIcon(QIcon(":/images/flipHor.png"));
    //m_data->flipHor->setShortcut(QKeySequence:://);
    m_data->flipHorAction->setStatusTip(tr("Flip Horizontally"));
    connect(m_data->flipHorAction, SIGNAL(triggered()),
            this, SLOT(flipHorizontally()));

}

void ImageWindow::createMenus()
{
    m_data->fileMenu = menuBar()->addMenu(tr("&File"));
    m_data->fileMenu->addAction(m_data->openAction);
    m_data->fileMenu->addAction(m_data->saveAction);
    m_data->fileMenu->addAction(m_data->saveAsAction);
    m_data->fileMenu->addSeparator();
    m_data->fileMenu->addAction(m_data->exitAction);

    m_data->editMenu = menuBar()->addMenu(tr("&Edit"));
    m_data->editMenu->addAction(m_data->flipHorAction);

    menuBar()->addSeparator();

    m_data->helpMenu = menuBar()->addMenu(tr("&Help"));
}

void ImageWindow::allTransactionsDone()
{
    m_data->openAction->setEnabled(true);
    m_data->saveAction->setEnabled(true);
    m_data->saveAsAction->setEnabled(true);
    m_data->imageLabel->setPixmap(QPixmap::fromImage(m_data->thread.image()));
    //setWindowModified(true);
    statusBar()->showMessage(tr("Ready"), 2000);
}

void ImageWindow::flipHorizontally()
{
    //m_data->flip = new FlipTransaction(Qt::Horizontal);
    addTransaction(new FlipTransaction(Qt::Horizontal));
}

void ImageWindow::addTransaction(Transaction *transact)
{
    m_data->thread.addTransaction(transact);
    m_data->openAction->setEnabled(false);
    m_data->saveAction->setEnabled(false);
    m_data->saveAsAction->setEnabled(false);
}

void ImageWindow::setCurrentFile(const QString &file)
{
    m_data->file = file;
}

void ImageWindow::openImage()
{
    // open
}

void ImageWindow::saveImage()
{
    // save
}

void ImageWindow::saveAsImage()
{
    // save as
}

void ImageWindow::exit()
{
    // exit
}
