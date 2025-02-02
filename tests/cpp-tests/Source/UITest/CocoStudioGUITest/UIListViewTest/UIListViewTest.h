/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 https://axmolengine.github.io/

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __TestCpp__UIListViewTest__
#define __TestCpp__UIListViewTest__

#include "../UIScene.h"
#include "ui/UIScrollView.h"

DEFINE_TEST_SUITE(UIListViewTests);

class UIListViewTest_Vertical : public UIScene
{
public:
    CREATE_FUNC(UIListViewTest_Vertical);

    UIListViewTest_Vertical();
    ~UIListViewTest_Vertical();

    virtual bool init() override;
    void selectedItemEvent(ax::Object* sender, ax::ui::ListView::EventType type);
    void selectedItemEventScrollView(ax::Object* sender, ax::ui::ScrollView::EventType type);
    virtual void update(float dt) override;

protected:
    float getItemPositionYInView(ax::ui::Widget* item) const;
    void updateItem(int itemID, int templateID);

    ax::ui::Text* _displayValueLabel = nullptr;
    // How many items we actually spawn, these items will be reused.
    // Should > listview.width / templateWidth + 2.
    int _spawnCount = 5;
    // How many items we need for the ListView. Usually this is a big number.
    int _totalCount = 50;
    // when item is away from bufferSzone, we relocate it.
    // Should be larger than List item width.
    float _bufferZone         = 45.f;
    float _itemTemplateHeight = 0.f;
    // Could tweak this value to adjust ListView data update rate.
    float _updateInterval = (1.0f / 24);
    float _updateTimer    = 0.f;
    // Use this value to detect if we are scrolling left or right
    float _lastContentPosY           = 0.f;
    float _reuseItemOffset           = 0.f;
    ax::ui::ListView* _listView = nullptr;
    std::vector<std::string> _array;
    ax::ui::Text* _indexLabels[3] = {nullptr};
};

class UIListViewTest_Horizontal : public UIScene
{
public:
    CREATE_FUNC(UIListViewTest_Horizontal);

    UIListViewTest_Horizontal();
    ~UIListViewTest_Horizontal();

    virtual bool init() override;
    void selectedItemEvent(ax::Object* sender, ax::ui::ListView::EventType type);
    virtual void update(float dt) override;

protected:
    float getItemPositionXInView(ax::ui::Widget* item) const;
    void updateItem(int itemID, int templateID);

    ax::ui::Text* _displayValueLabel = nullptr;
    // How many items we actually spawn, these items will be reused.
    // Should > listview.width / templateWidth + 2.
    int _spawnCount = 4;
    // How many items we need for the ListView. Usually this is a big number.
    int _totalCount = 50;
    // when item is away from bufferSzone, we relocate it.
    float _bufferZone        = 140.f;
    float _itemTemplateWidth = 0.f;
    // Could tweak this value to adjust ListView data update rate.
    float _updateInterval            = 1.0f / 24;
    float _updateTimer               = 0.f;
    float _lastContentPosX           = 0.f;
    float _reuseItemOffset           = 0.f;
    ax::ui::ListView* _listView = nullptr;

    std::vector<std::string> _array;
};

class Issue12692 : public UIScene
{
public:
    CREATE_FUNC(Issue12692);

    virtual bool init() override;
};

class Issue8316 : public UIScene
{
public:
    CREATE_FUNC(Issue8316);

    virtual bool init() override;
};

// Test for scroll to item
class UIListViewTest_ScrollToItem : public UIScene
{
protected:
    virtual bool init() override;
    virtual ax::ui::ScrollView::Direction getListViewDirection() const = 0;

    ax::ui::ListView* _listView;
    ax::ui::Text* _titleLabel;
    int _nextIndex;
};

class UIListViewTest_ScrollToItemVertical : public UIListViewTest_ScrollToItem
{
public:
    CREATE_FUNC(UIListViewTest_ScrollToItemVertical);
    virtual ax::ui::ScrollView::Direction getListViewDirection() const
    {
        return ax::ui::ScrollView::Direction::VERTICAL;
    }
};

class UIListViewTest_ScrollToItemHorizontal : public UIListViewTest_ScrollToItem
{
public:
    CREATE_FUNC(UIListViewTest_ScrollToItemHorizontal);
    virtual ax::ui::ScrollView::Direction getListViewDirection() const
    {
        return ax::ui::ScrollView::Direction::HORIZONTAL;
    }
};

// Test for magnetic scroll
class UIListViewTest_Magnetic : public UIScene
{
protected:
    virtual bool init() override;
    virtual ax::ui::ScrollView::Direction getListViewDirection() const = 0;

    ax::ui::ListView* _listView;
    ax::ui::Text* _titleLabel;
    ax::ui::Text* _indexLabels[5];
};

class UIListViewTest_MagneticVertical : public UIListViewTest_Magnetic
{
public:
    CREATE_FUNC(UIListViewTest_MagneticVertical);
    virtual ax::ui::ScrollView::Direction getListViewDirection() const
    {
        return ax::ui::ScrollView::Direction::VERTICAL;
    }
};

class UIListViewTest_MagneticHorizontal : public UIListViewTest_Magnetic
{
public:
    CREATE_FUNC(UIListViewTest_MagneticHorizontal);
    virtual ax::ui::ScrollView::Direction getListViewDirection() const
    {
        return ax::ui::ScrollView::Direction::HORIZONTAL;
    }
};

// Test for setting padding
class UIListViewTest_Padding : public UIScene
{
protected:
    virtual bool init() override;
    virtual ax::ui::ScrollView::Direction getListViewDirection() const = 0;

    void sliderEvent(ax::Object* pSender, ax::ui::Slider::EventType type);

    ax::ui::ListView* _listView;
    ax::ui::Text* _titleLabel;
    ax::ui::Text* _indexLabels[5];
    ax::ui::Text* _paddingLabels[4];
};

class UIListViewTest_PaddingVertical : public UIListViewTest_Padding
{
public:
    CREATE_FUNC(UIListViewTest_PaddingVertical);
    virtual ax::ui::ScrollView::Direction getListViewDirection() const
    {
        return ax::ui::ScrollView::Direction::VERTICAL;
    }
};

class UIListViewTest_PaddingHorizontal : public UIListViewTest_Padding
{
public:
    CREATE_FUNC(UIListViewTest_PaddingHorizontal);
    virtual ax::ui::ScrollView::Direction getListViewDirection() const
    {
        return ax::ui::ScrollView::Direction::HORIZONTAL;
    }
};

#endif /* defined(__TestCpp__UIListViewTest__) */
