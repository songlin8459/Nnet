#include "map.h"
#include "config.h"


Map::Map()
{
    // 初始化加载地图对象
    QPixmap tmp_m_map(MAP_PATH);

    m_map1 = tmp_m_map.scaled(GAME_WIDTH, GAME_HEIGHT,
                              Qt::IgnoreAspectRatio,
                              Qt::SmoothTransformation);
    m_map2 = tmp_m_map.scaled(GAME_WIDTH, GAME_HEIGHT,
                             Qt::IgnoreAspectRatio,
                             Qt::SmoothTransformation);

    // 初始化Y轴坐标
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;

    // 地图滚动速度
    m_scroll_speed = MAP_SCROLL_SPEED;
}


void Map::mapPosition()
{
   // 处理第一张图片的位置
   m_map1_posY += m_scroll_speed;
   if (m_map1_posY>=0)
   {
       m_map1_posY = -GAME_HEIGHT;
   }

   // 处理第二张图片的位置
   m_map2_posY += m_scroll_speed;
   if (m_map2_posY>=GAME_HEIGHT)
   {
       m_map2_posY = 0;
   }
}
