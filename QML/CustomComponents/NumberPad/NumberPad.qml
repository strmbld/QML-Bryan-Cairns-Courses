import QtQuick
import QtQuick.Controls 6.2


Item {
    id: root

    signal clicked(int value)

    Column {
        id: col

        Grid {
            id: grid
            spacing: 5
            rows: 4
            columns: 3
        }
    }

    function doClicked(value) {
        clicked(value)
    }

    Component.onCompleted: {
        let num = 0

        for(let i = 0; i < 10; ++i) {
            if(i === 0) num = 7;
            if(i === 3) num = 4;
            if(i === 6) num = 1;
            if(i === 9) num = 0;

            let btn = Qt.createQmlObject(
                    'import QtQuick; import QtQuick.Controls 6.2; Button {id: btn' + i + '; onClicked:doClicked(' + num + ')}',
                    grid,
                    "DynamicallyCreatedQmlObj"
                    )

            btn.text = num
            btn.width = 40
            btn.height = 40
            num++
        }

        let lastBtn = grid.children[grid.children.length - 1]
        lastBtn.parent = col
        lastBtn.width = 40 * grid.columns + 10
    }
}
