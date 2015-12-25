--- src/Cell.cpp
+++ src/Cell.cpp
@@ -1,5 +1,20 @@
 #include "Cell.h"
 
+namespace Sudoku {
+
 Cell::Cell()
 {
 }
+
+Cell &Cell::operator=(const Cell &rhs)
+{
+    if (this != &rhs)
+    {
+        if (rhs.m_value)
+
+    }
+
+    return *this;
+}
+
+} // namespace Sudoku
