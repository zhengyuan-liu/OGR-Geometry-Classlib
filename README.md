# OGR-Geometry-Classlib
OGR Architecture Geometry Classlib simplified version

在GIS中，矢量数据的存储、显示、分析等均依赖于矢量几何要素。矢量几何要素是GIS中最重要的数据结构之一。常见的几何要素有简单点(Point)、简单线(Line)和简单面(Polygon)，以及它们的复杂形式如复杂点(MultiPoint)、折线(PolyLine)和复杂线(MultiPolyline)、复杂多边形(MultiPolygon)等。除此之外，还有曲线(Curve)、环(Ring)等几何要素形式。这些几何要素之间存在着复杂的关系，比如：有些复杂要素是简单的要素的集合，当然也可以认为简单要素是复杂要素最特殊最简单化的一种；有些要素则可视为另外一些要素的组合；有些要素则是其他要素的子类。

针对矢量几何要素以及它们之间的关系，业界存在着多种类（class）及体系关系描述形式，其中OGC（OpenGIS协会，Open Geospatial Consortium）给出的OpenGIS（Open Geodata Interoperation Specification, OGIS-开放的地理数据互操作规范）simple features data model得到了业界的广泛认可。/** OGC是一个非赢利性组织，目的是促进采用新的技术和商业方式来提高地理信息处理的互操作性(Interoperability)，它致力于消除地理信息应用（如地理信息系统，遥感，土地信息系统，自动制图/设施管理系统之间以及地理应用与其它信息技术应用之间的藩篱，建立一个无“边界”的、分布的、基于构件的地理数据互操作环境。**/

下图即为GDAL(Geospatial Data Abstraction Library)中OGR Architecture对OpenGIS simple features data model中部分矢量要素（geometry）的实现架构。OGR库的应用十分广泛，包括ARCGIS 9.3、Google Earth和跨平台的GRASS GIS系统均采用了该模型。/** GDAL是一个在X/MIT许可协议下的开源空间数据转换库。它利用抽象数据模型来表达所支持的各种文件格式，拥有一系列命令行工具来进行数据转换和处理，其主要目标是实现数据共享和互操作。OGR是GDAL项目的一个分支，提供对矢量数据的支持。**/

![](http://www.gdal.org/classOGRGeometry.png)

根据上图以及参考资料，使用C++对OGR Architecture进行简化版的实现。
