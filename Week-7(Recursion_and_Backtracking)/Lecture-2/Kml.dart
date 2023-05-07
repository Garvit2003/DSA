




Future<File> writeCounter(int counter) async {
final file = await _localFile;
// Write the file
return file.writeAsString('$counter');
}



Future<int> readCounter() async {
try {
final file = await _localFile;
// Read the file
final contents = await file.readAsString();
return int.parse(contents);
} catch (e) {
// If encountering an error, return 0
return 0;
}
}

import 'dart:io';
// ignore: import_of_legacy_library_into_null_safe
import 'package:path_provider/path_provider.dart';
class KMLGenerator {
  static generateKML(data, filename) async {
    try {
    final downloadsDirectory =
            await DownloadsPathProvider.downloadsDirectory;
        var savePath = downloadsDirectory.path;
        final file = File("$savePath/$filename.kml");
        await file.writeAsString(data);
        return Future.value(file);
    } catch (e) {
      print(e);
                return Future.error(e);
    }
  }
}