#pragma once

#include "../imagesData/ImagesData.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QFile>
#include <QSize>
#include <QResource>
#include <QtConcurrent/QtConcurrent>

#include <iostream>
#include <fstream>
#include "../../display/box/Box.h"
#include "../../structure/folders/Folders.h"
#include "../../structure/sizes/Sizes.h"
#include "../../structure/threadPool/ThreadPool.h"

#include <QFileDialog>

class QImageAndPath {
public:
    QImage image;
    std::string imagePath;
};

class Data {
public:
    ImagesData imagesData;
    ImagesData deletedImagesData;
    Folders rootFolders = Folders("/");
    Sizes sizes;
    std::map<std::string, Option> options = DEFAULT_OPTIONS;
    ThreadPool threadPool = ThreadPool(std::thread::hardware_concurrency() / 2);
    std::map<QString, std::future<void>> futures;
    std::map<std::string, QImageAndPath>* imageCache = nullptr;

    void preDeleteImage(int imageNbr);
    void unPreDeleteImage(int imageNbr);

    void revocerDeletedImage(int imageNbr);
    void revocerDeletedImage(ImageData& imageData);

    void removeDeletedImages();

    QImage loadImage(QWidget* parent, std::string imagePath, QSize size, bool setSize, int thumbnail = 0, bool rotation = true, bool square = false, bool crop = true);
    QImage loadImageNormal(QWidget* parent, std::string imagePath, QSize size, bool setSize, int thumbnail = 0);
    // QImage loadImageSquare(QWidget* parent, std::string imagePath, QSize size, bool setSize, int thumbnail = 0);

    bool loadInCache(std::string imagePath, bool setSize = false, QSize size = QSize(0, 0), bool force = false);
    void loadInCacheAsync(std::string imagePath, std::function<void()> callback, bool setSize = false, QSize size = QSize(0, 0), bool force = false);


    bool unloadFromCache(std::string imagePath);
    bool unloadFromFutures(std::string imagePath);

    bool isInCache(std::string imagePath);
    bool getLoadedImage(std::string imagePath, QImage& image);

    void createThumbnails(const std::vector<std::string>& imagePaths, const int maxDim);
    void createThumbnail(const std::string& imagePath, const int maxDim);

    void createThumbnailsIfNotExists(const std::vector<std::string>& imagePaths, const int maxDim);

    void createThumbnailIfNotExists(const std::string& imagePath, const int maxDim);

    bool hasThumbnail(const std::string& imagePath, const int maxDim);

    void createAllThumbnail(const std::string& path, const int maxDim);

    std::string getThumbnailPath(const std::string& imagePath, const int size);

    void exportImages(std::string exportPath, bool dateInName);


    void saveData();
    void loadData();

    void cancelTasks();
    bool isDeleted(int imageNbr);

private:
    void loadImageTask(std::string imagePath, bool setSize, QSize size, bool force, std::function<void()> callback);
    QImage rotateQImage(QImage image, std::string imagePath);

    Folders* findFirstFolderWithAllImages(const ImagesData& imagesData, const Folders& currentFolder) const;
    void copyImages(Folders* currentFolders, std::string path, bool dateInName);
    void copyTo(std::string filePath, std::string destinationPath, bool dateInName) const;
};
