
#ifndef WINDOW_H
#define WINDOW_H

//#include <QWidget>

class Window/* : public QWidget*/
{
    //Q_OBJECT

    public:
        Window(/*QWidget *parent = 0*/);
        ~Window();

    private:
        void init();

    //private slots:
        //void test();

    private:
        class PrivateData;
        PrivateData *m_data;

};

#endif
