#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <vector>
#include <QTimer>


#include "../../structure/data/Data.h"
#include "../../display/clickableLabel/ClickableLabel.h"
// #include "../../display/imageEditor/ImageEditor.h"
#include "../../display/initialWindow/InitialWindow.h"





class ImageBooth : public QMainWindow {
    Q_OBJECT

public:

    ImageBooth(Data* dat, QWidget* parent = nullptr);
    ~ImageBooth() {}

    void clear();
private:
    Data* data;
    // QSize screenGeometry;
    int imageNumber;
    QScrollArea* scrollArea;

    QHBoxLayout* mainLayout;
    QVBoxLayout* linesLayout;

    QSize imageSize = data->sizes.imagesBoothSizes->imageSize;
    QSize realImageSize = data->sizes.imagesBoothSizes->realImageSize;



    ClickableLabel* createImage(std::string imagePath, int nbr);
    void createLine();
    void setImageNumber(int nbr);
signals:
    void switchToImageEditor();
};

