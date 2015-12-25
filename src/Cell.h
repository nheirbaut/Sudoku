--- src/Cell.h
+++ src/Cell.h
@@ -1,10 +1,24 @@
 #ifndef CELL_H
 #define CELL_H
 
+#include <cstdint>
+
+namespace Sudoku {
+
 class Cell
 {
 public:
+
+    using Type = std::uint8_t;
+
+public:
+
     Cell();
-};
+
+    Cell& operator=(const Cell& rhs);
+
+}; // class Cell
+
+} // namespace Sudoku
 
 #endif // CELL_H
